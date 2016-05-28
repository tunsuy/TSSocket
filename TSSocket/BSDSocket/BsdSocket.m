//
//  BsdSocket.m
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "BsdSocket.h"
#import <arpa/inet.h>
#import <netdb.h>

@implementation BsdSocket

- (void)loadDataFromServerWithServerDomain:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback {
    NSString *host = [NetHelper getIPWithHostName:serverDomain];
    [self loadDataFromServerWithHost:host port:port resultCallBack:callback];    
}

- (void)loadDataFromServerWithHost:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback {
    dispatch_queue_t globalQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(globalQueue, ^{
        [self loadDataFromServerForConcurrenceWithHost:host port:port resultCallBack:callback];
    });
    
}

- (void)loadDataFromServerForConcurrenceWithHost:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback {
    int socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == socketFileDescriptor) {
        NSLog(@"Failed to create socket");
        NSString *errorMessage = @"Unable to resolve the hostName of server";
        dispatch_async(dispatch_get_main_queue(), ^{
           callback(errorMessage);
        });
        return;
    }

    struct hostent *remoteHostent = gethostbyname([serverDomain UTF8String]);
    if (NULL == remoteHostent) {
        close(socketFileDescriptor);
        return;
    }
    
    struct in_addr *remoteInAddr = (struct in_addr *)remoteHostent->h_addr_list[0];
    
    struct sockaddr_in socketParameters;
    socketParameters.sin_family = AF_INET;
    socketParameters.sin_addr = *remoteInAddr;
    socketParameters.sin_port = htons(port);
    
    int ret = connect(socketFileDescriptor, (struct sockaddr *)&socketParameters, sizeof(socketParameters));
    if (-1 == ret) {
        close(socketFileDescriptor);
        return;
    }
    NSLog(@"Successfully connected to %@:%d", serverDomain, port);
    
    NSMutableData *data = [[NSMutableData alloc] init];
    BOOL waitingForData = YES;
    int maxCount = 5, i = 0;
    while (waitingForData && i < maxCount) {
        const char *buffer[1024];
        int length = sizeof(buffer);
        
        int result = (int)recv(socketFileDescriptor, &buffer, length, 0);
        if (result > 0) {
            [data appendBytes:buffer length:result];
        }
        else {
            waitingForData = NO;
        }
        ++i;
    }
    dispatch_async(dispatch_get_main_queue(), ^{
        callback(data);
    });
    close(socketFileDescriptor);
}

@end
