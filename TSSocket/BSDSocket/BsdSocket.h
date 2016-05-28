//
//  BsdSocket.h
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^TSCallBack)(id result);

@interface BsdSocket : NSObject

- (void)loadDataFromServerWithServerDomain:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback;
- (void)loadDataFromServerWithHost:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback;

@end
