//
//  NSSocket.m
//  TSSocket
//
//  Created by tunsuy on 26/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "NSSocket.h"

#define kBufferSize 1024

@interface NSSocket ()

@property (nonatomic, weak) TSCallBack callBack;
@property (nonatomic, strong) NSMutableData *totalData;

@end

@implementation NSSocket

- (instancetype)init {
    if (self = [super init]) {
        _totalData = [[NSMutableData alloc] init];
        
    }
    return self;
}

- (void)setCallBack:(TSCallBack)callBack {
    if (!_callBack) {
        _callBack = callBack;
    }
}

#pragma mark - 带delegate的方法
/** 需要业务方自己实现NSStream的代理 */
- (void)loadDataFromServerWithDelegate:(id<NSStreamDelegate>)delegate serverDomain:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback {
    self.callBack = callback;
    NSString *host = [NetHelper getIPWithHostName:serverDomain];
    [self loadDataFromServerWithDelegate:delegate host:host port:port resultCallBack:callback];
}

- (void)loadDataFromServerWithDelegate:(id<NSStreamDelegate>)delegate host:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback {
    self.callBack = callback;
    NSInputStream *readStream;
    [self loadDataFromServerWithStream:readStream host:host port:port resultCallBack:callback];
    [readStream setDelegate:delegate];
}

#pragma mark - 不带delegate的方法
/** 不需要业务方实现NSStream的代理 */
- (void)loadDataFromServerWithServerDomain:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback {
    self.callBack = callback;
    NSString *host = [NetHelper getIPWithHostName:serverDomain];
    [self loadDataFromServerWithHost:host port:port resultCallBack:callback];
}

- (void)loadDataFromServerWithHost:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback {
    self.callBack = callback;
    NSInputStream *readStream;
    [self loadDataFromServerWithStream:readStream host:host port:port resultCallBack:callback];
    [readStream setDelegate:self];
}

#pragma mark - NSStreamDelegate
- (void)stream:(NSStream *)aStream handleEvent:(NSStreamEvent)eventCode {
    NSLog(@" >> NSStreamDelegate in Thread %@", [NSThread currentThread]);
    switch (eventCode) {
        case NSStreamEventHasBytesAvailable: {
            uint8_t buffer[kBufferSize];
            NSInteger realDataLen = [(NSInputStream *)aStream read:buffer maxLength:kBufferSize];
            if (realDataLen > 0) {
                NSData *data = [NSData dataWithBytes:buffer length:realDataLen];
                [self.totalData appendData:data];
//                self.callBack(data);
            }
            else if (realDataLen == 0) {
                NSLog(@">> End of stream");
            }
            else {
                NSLog(@">> Read stream error");
            }
            break;
        }
        case NSStreamEventErrorOccurred: {
            NSError *error = [(NSInputStream *)aStream streamError];
            NSString *errorInfo = [NSString stringWithFormat:@">> Error while read stream , error:%@ %d", error.localizedDescription, error.code];
            [self cleanUpStream:aStream];
            self.callBack(errorInfo);
            break;
        }
        case NSStreamEventEndEncountered: {
            [self cleanUpStream:aStream];
            self.callBack(self.totalData);
            break;
        }
            
        default:
            break;
    }
}

#pragma mark - private sel
- (void)loadDataFromServerWithStream:(NSStream *)stream host:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback {
    [NSStream getStreamsToHostWithName:host port:port inputStream:&stream outputStream:NULL];
    [stream scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    [stream open];
    [[NSRunLoop currentRunLoop] run];
}

- (void)cleanUpStream:(NSStream *)stream {
    [stream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    [stream close];
    stream = nil;
}

@end
