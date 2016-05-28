//
//  Connecter.m
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "Connecter.h"
#import "Connecter+ProtoInterface.h"
#import "AsyncTcpSocket.h"

@interface Connecter ()<AsyncTcpSocketDelegate>

@property (nonatomic) BOOL isConnecting;
@property (nonatomic, strong) AsyncTcpSocket *asyncSocket;

@end

@implementation Connecter

- (instancetype)initWithIP:(NSString *)ip port:(uint16_t)port {
    if (self = [super init]) {
        _ip = ip;
        _port = port;
    }
    return self;
}

- (NSError *)connectedInTimeout:(NSTimeInterval)timeout {
    self.asyncSocket = [[AsyncTcpSocket alloc] init];
    [self.asyncSocket connectToHost:self.ip onPort:self.port withTimeout:timeout];
    return nil;
}

- (NSUInteger)getAnUnusedPacketID {
    self.currentPacketID++;
    NSUInteger packetID = self.currentPacketID;
    return packetID;
}

- (void)resetKeepAliveChecker
{
    [NSThread cancelPreviousPerformRequestsWithTarget:self];
    [self performSelector:@selector(sendHeartBeat) withObject:nil afterDelay:HEART_BEAT_INTERVAL];
}

//- (void)sendHeartBeat
//{
//    NSLog(@"Warn: send heart beat");
//    CGFloat timeout = 3.0;
//    NSInteger oprType = SRVOP_DISP_ECHO_REQ;
//    NSData *data = [NSData dataWithBytes:NULL length:0];
//    
//    __weak typeof(self) weakself = self;
//    NetCallback callback = ^(NSNumber* chanID, id result, NSError *error) {
//        if(error && weakself) {
//            [NSThread cancelPreviousPerformRequestsWithTarget:weakself];
//            [weakself heartBearTimeout];
//        }
//    };
//    
//    NSMutableDictionary *callArgDict = [NSMutableDictionary dictionaryWithDictionary:@{@"oprType": @(oprType),
//                                                                                       @"timeout": @(timeout+1),
//                                                                                       @"SSize": @(0),
//                                                                                       @"startDate": [NSDate date],
//                                                                                       @"callback": callback,
//                                                                                       }];
//    [self sendPacketWithSrvop:oprType andData:data andPacketType:ePacketTypeProto andCallArgDict:callArgDict];
//    [self performSelector:@selector(heartBearTimeout) withObject:nil afterDelay:timeout];
//}

//- (void)heartBearTimeout
//{
//    NSLog(@"Warn: heart beat timeout");
//    [self asyncDisconnect];
//}

//- (void)asyncDisconnect
//{
//    [NSThread cancelPreviousPerformRequestsWithTarget:self];
//    
//    if(self.isConnecting == YES && self.delegate) {
//        NSLog(@"To disconnect:%@", self.chanID);
//    }
//    self.isConnecting = NO;
//    [self.asyncSocket asyncDisconnect];
//}
//
//- (void)socket:(AsyncTcpSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port {
//    [self resetKeepAliveChecker];
//    
//    NSAssert([sock isEqual:self.asyncSocket], nil);
//    self.isConnecting = NO;
//    if (! [self.delegate socketShouldConsultAfterLink:self]) {
//        NSLogToFile(@"Warn: socketShouldConsultAfterLink=NO");
//        [self asyncDisconnect];
//        return;
//    }else{
//        if (self.recvData == nil) {
//            self.recvData = [NSMutableData dataWithCapacity:kDefaultBuffSize];
//            self.requests = [NSMutableDictionary dictionaryWithCapacity:30];
//        }
//        [self sayHello];
//        NSAssert(self.recvData.length == 0 && self.newRecvIndex == 0, @"must be empty first");
//    }
//}

- (void)socket:(AsyncTcpSocket *)sock didReadData:(NSData *)data {
    
}

- (void)socket:(AsyncTcpSocket *)sock timeoutForTag:(NSInteger)tag disconnect:(BOOL)disconnect {
    NSNumber *packetID = @(tag);
    NSMutableDictionary *configDict = self.requests[packetID];
    if (! configDict) {
        NSLog(@"Warn: get a timeout ignore:%@", packetID);
        return ;
    }
    [self.requests removeObjectForKey:packetID];
    
    if(disconnect == NO && configDict[@"retryInfo"]) {
        NSMutableDictionary *retryInfo = configDict[@"retryInfo"];
        NSAssert([retryInfo isKindOfClass:[NSMutableDictionary class]], nil);
        NSInteger errorCount = [retryInfo[@"errorCount"] integerValue] + 1;
        if([retryInfo[@"retryCount"] integerValue] > errorCount) {
            retryInfo[@"errorCount"] = @(errorCount);
            NSLog(@"Info: retry request(%@) maxCount:%@ errorCount:%@ sleep:%@", retryInfo[@"srvop"], retryInfo[@"retryCount"], retryInfo[@"errorCount"], retryInfo[@"sleep"]);
            
            NSNumber *packetID = @([self getAnUnusedPacketID]);
            NSAssert(self.requests[packetID] == nil, nil);
            self.requests[packetID] = configDict;
            
            NSTimeInterval sleep = [retryInfo[@"sleep"] floatValue];
            __weak typeof(self) weakself = self;
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(sleep * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                if(weakself) {
                    NSData *data = retryInfo[@"data"];
                    NSInteger srvop = [retryInfo[@"srvop"] integerValue];
                    NSInteger packetType = [retryInfo[@"packetType"] integerValue];
                    [weakself sendPacketWithSrvop:srvop andData:data andPacketType:packetType packetID:packetID andCallArgDict:configDict];
                }
            });
            return;
        }
        
        NSLog(@"Info: retry request(%@) break because reach max retry(%@)", retryInfo[@"srvop"], retryInfo[@"retryCount"]);
    }
}

- (void)socketDidDisconnect:(AsyncTcpSocket *)sock withError:(NSError *)err {
    
}

@end
