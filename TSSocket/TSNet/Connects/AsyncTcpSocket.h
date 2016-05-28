//
//  AsyncTcpSocket.h
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AsyncTcpSocket;

@protocol AsyncTcpSocketDelegate <NSObject>

- (void)socket:(AsyncTcpSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port;
- (void)socket:(AsyncTcpSocket *)sock didReadData:(NSData *)data;
- (void)socket:(AsyncTcpSocket *)sock timeoutForTag:(NSInteger)tag disconnect:(BOOL)disconnect;
- (void)socketDidDisconnect:(AsyncTcpSocket *)sock withError:(NSError *)err;

@end

@interface AsyncTcpSocket : NSObject

@property (nonatomic, strong) NSString *ip;
@property (nonatomic) NSUInteger port;

- (void)connectToHost:(NSString *)host
               onPort:(uint16_t)port
          withTimeout:(NSTimeInterval)timeout;

- (void)removeTimerWithTag:(NSNumber *)tag;
- (void)sendData:(NSData *)data withTimeout:(NSTimeInterval)timeout andTag:(NSInteger)tag;
- (BOOL)isConnected;
- (void)asyncDisconnect;

@end
