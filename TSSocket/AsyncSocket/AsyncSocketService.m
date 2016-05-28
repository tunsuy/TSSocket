//
//  AsyncSocketService.m
//  TSSocket
//
//  Created by tunsuy on 25/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "AsyncSocketService.h"
#import "AsyncSocket.h"
#import <netdb.h>

static double const timeout = 60.0;

typedef NS_ENUM(NSInteger, SocketOfflineType) {
    SocketOfflineTypeByServer,
    SocketOfflineTypeByUser
};

@interface AsyncSocketService ()<AsyncSocketDelegate>

@property (nonatomic, strong) NSTimer *connectTimer; //计时器
@property (nonatomic) SocketOfflineType socketOfflineType;
@property (nonatomic, strong) AsyncSocket *asyncSocket;

@end

@implementation AsyncSocketService

- (instancetype)init {
    if (self = [super init]) {
        self.asyncSocket = [[AsyncSocket alloc] initWithDelegate:self];
    }
    return self;
}

- (void)connectToServerDomain:serverDomain onPort:(NSUInteger)port {
    NSString *host = [NetHelper getIPWithHostName:serverDomain];
    [self connectToHost:host onPort:port];
}

- (void)connectToHost:host onPort:(NSUInteger)port {
    [self.asyncSocket connectToHost:host onPort:port error:nil];
}

/** 在长连接中计时 */
- (void)onSocket:(AsyncSocket *)sock didConnectToHost:(NSString *)host port:(UInt16)port {
    NSLog(@"Successed connect to %@:%d", host, port);
    self.connectTimer = [NSTimer scheduledTimerWithTimeInterval:timeout target:self selector:@selector(longConnectSocket:) userInfo:nil repeats:YES];
    [self.connectTimer fire];
}

/** 发送心跳包 */
- (void)longConnectSocket:(NSTimer *)timer {
    NSString *heartbeat = @"heartbeat packet";
    NSData *dataStream = [heartbeat dataUsingEncoding:NSUTF8StringEncoding];
    [self.asyncSocket writeData:dataStream withTimeout:timeout tag:1];
    /** 正确的做法是还需要发送一个头部 */
}

/** 用户主动断开网络 */
- (void)cutOffSocket {
    self.socketOfflineType = SocketOfflineTypeByUser;
    [self.connectTimer invalidate];
    [self.asyncSocket disconnect];
}

- (void)onSocketDidDisconnect:(AsyncSocket *)sock {
    NSLog(@"connect is failure %ld", self.socketOfflineType);
    if (self.socketOfflineType == SocketOfflineTypeByServer) {
        NSString *serverDomain = [self.asyncSocket connectedHost];
        NSUInteger port = [self.asyncSocket connectedPort];
        
        [self.asyncSocket connectToHost:serverDomain onPort:port error:nil];
    }
    else if (self.socketOfflineType == SocketOfflineTypeByUser) {
        return;
    }
}

- (void)onSocket:(AsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag {
    
    /** 对接收到的数据进行解析处理 */
    
    [self.asyncSocket readDataWithTimeout:timeout tag:1];
}

@end
