//
//  AsyncTcpSocket.m
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "AsyncTcpSocket.h"

typedef NS_ENUM(NSUInteger, eConnectState) {
    eConnectStateInit = 0,
    eConnectStateConnected,
    eConnectStateDisconnect,
};

static NSString *const kConnectTimerName = @"connectTimerName";

@interface AsyncTcpSocket ()<NSStreamDelegate>

@property (nonatomic, strong) NSInputStream *inputStream;
@property (nonatomic, strong) NSOutputStream *outputStream;
@property (nonatomic, strong) NSMutableDictionary *timers;
@property (nonatomic)         eConnectState connectState;

@property (nonatomic, weak) id<AsyncTcpSocketDelegate> delegate;

@end

@implementation AsyncTcpSocket

- (void)connectToHost:(NSString *)host onPort:(uint16_t)port withTimeout:(NSTimeInterval)timeout {
    NSAssert(self.ip == nil, nil);
    NSAssert(host != nil, nil);
    self.ip = host;
    self.port = port;
    dispatch_block_t block = ^{
        NSAssert(port > 0, nil);
        CFReadStreamRef readStream = NULL;
        CFWriteStreamRef writeStream = NULL;
        CFStreamCreatePairWithSocketToHost(kCFAllocatorDefault, (__bridge CFStringRef)self.ip, self.port, &readStream, &writeStream);
        
        self.inputStream = (__bridge_transfer NSInputStream *)readStream;
        self.outputStream = (__bridge_transfer NSOutputStream *)writeStream;
        
        self.inputStream.delegate = self;
        self.outputStream.delegate = self;
        
        [self.inputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        [self.outputStream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
        [self.inputStream open];
        [self.outputStream open];
        
        if (timeout > 0) {
            NSTimer *connectTimer = [NSTimer scheduledTimerWithTimeInterval:timeout target:self selector:@selector(timerFireMethod:) userInfo:kConnectTimerName repeats:NO];
            self.timers[kConnectTimerName] = connectTimer;
        }
    };
}

//- (void)timerFireMethod:(NSTimer *)timer {
//    NSAssert(timer.isValid, nil);
//    id userInfo = timer.userInfo;
//    if (userInfo && self.timers[userInfo]) {
//        if (timer.isValid) {
//            [timer invalidate];
//        }
//        
//        if ([userInfo isKindOfClass:[NSString class]]) {
//            if ([userInfo isEqualToString:kConnectTimerName]) {
//                NSLog(@"connect timeout");
//                [self closeWithError:MOAErrorMakeOther(@"net error", @"Connect timeout", 0)];
//            }
//        }else if ([userInfo isKindOfClass:[NSNumber class]]) {
//            [self.delegate socket:self timeoutForTag:[userInfo integerValue] disconnect:NO];
//        }
//        [self.timers removeObjectForKey:userInfo];
//        
//    }
//}

- (void)closeWithError:(NSError *)error
{
    if(error) {
        NSLog(@"Close with Reason:<%p>%@, %@", self, error, self.delegate);
    }
    if (self.connectState == eConnectStateDisconnect) {
        return;
    }
    
    self.connectState = eConnectStateDisconnect;
    
    NSArray *keys = [self.timers allKeys];
    for (id key in keys) {
        NSTimer *timer = self.timers[key];
        [self.timers removeObjectForKey:key];
        id userInfo = nil;
        if (timer.isValid) {
            userInfo = timer.userInfo;
            [timer invalidate];
        }
        
        if ([key isKindOfClass:[NSNumber class]]) {
            NSAssert(userInfo == nil || [userInfo isEqual:key], nil);
            [self.delegate socket:self timeoutForTag:[key integerValue] disconnect:YES];
        }
        
    }
    
    [self.delegate socketDidDisconnect:self withError:error];
    
    self.delegate = nil;
    
}

@end
