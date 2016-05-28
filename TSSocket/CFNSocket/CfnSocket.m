//
//  CfnSocket.m
//  TSSocket
//
//  Created by tunsuy on 26/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "CfnSocket.h"

#define kBufferSize 1024

@interface CfnSocket ()

@property (nonatomic, weak) TSCallBack callBack;
@property (nonatomic, strong) NSMutableData *totalData;

@end

@implementation CfnSocket

- (instancetype)init {
    if (self = [super init]) {
        _totalData = [[NSMutableData alloc] init];
    }
    return self;
}

- (void)loadDataFromServerWithServerDomain:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback {
    NSString *host = [NetHelper getIPWithHostName:serverDomain];
    [self loadDataFromServerWithHost:host port:port resultCallBack:callback];
}

- (void)loadDataFromServerWithHost:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback {
    self.callBack = callback;
    CFStreamClientContext ctx = {0, (__bridge void *)(self), NULL, NULL, NULL};
    CFOptionFlags registeredEvents = (kCFStreamEventHasBytesAvailable | kCFStreamEventEndEncountered | kCFStreamEventErrorOccurred);
    CFReadStreamRef readStream;
    CFStreamCreatePairWithSocketToHost(kCFAllocatorDefault, (__bridge CFStringRef)host, port, &readStream, NULL);
    
    if (CFReadStreamSetClient(readStream, registeredEvents, socketCallback, &ctx)) {
        CFReadStreamScheduleWithRunLoop(readStream, CFRunLoopGetCurrent(), kCFRunLoopCommonModes);
    }
    else {
        NSString *errorInfo = @"Failed to assign callback method";
        self.callBack(errorInfo);
        return;
    }
    
    if (CFReadStreamOpen(readStream) == NO) {
        NSString *errorInfo = @"Failed to open the read stream";
        self.callBack(errorInfo);
        return;
    }
    
    CFErrorRef error = CFReadStreamCopyError(readStream);
    if (error != NULL) {
        if (CFErrorGetCode(error) != 0) {
            NSString * errorInfo = [NSString stringWithFormat:@"Failed to connect stream; error '%@' (code %ld)", (__bridge NSString*)CFErrorGetDomain(error), CFErrorGetCode(error)];
            self.callBack(errorInfo);
        }
        CFRelease(error);
        return;
    }
    
    NSLog(@"Successfully connect to %@:%d", host, port);
    
    CFRunLoopRun();
}

void socketCallback(CFReadStreamRef stream, CFStreamEventType event, void * myPtr) {
    NSLog(@" >> socketCallback in Thread %@", [NSThread currentThread]);
    CfnSocket *self = (__bridge CfnSocket *)myPtr;

	switch(event) {
        case kCFStreamEventHasBytesAvailable: {
            while (CFReadStreamHasBytesAvailable(stream)) {
				UInt8 buffer[kBufferSize];
                int numBytesRead = CFReadStreamRead(stream, buffer, kBufferSize);
                NSData *receiveData = [NSData dataWithBytes:buffer length:numBytesRead];
                [self.totalData appendData:receiveData];
//                self.callBack(receiveData);
			}
            break;
        }
        case kCFStreamEventErrorOccurred: {
			CFErrorRef error = CFReadStreamCopyError(stream);
			if (error != NULL) {
				if (CFErrorGetCode(error) != 0) {
					NSString * errorInfo = [NSString stringWithFormat:@"Failed while reading stream; error '%@' (code %ld)", (__bridge NSString*)CFErrorGetDomain(error), CFErrorGetCode(error)];
                    self.callBack(errorInfo);
				}
				CFRelease(error);
			}
            break;
		}
        case kCFStreamEventEndEncountered:
            self.callBack(self.totalData);

			CFReadStreamClose(stream);
			CFReadStreamUnscheduleFromRunLoop(stream, CFRunLoopGetCurrent(), kCFRunLoopCommonModes);
			CFRunLoopStop(CFRunLoopGetCurrent());
            break;
        default:
            break;
    }
}


@end
