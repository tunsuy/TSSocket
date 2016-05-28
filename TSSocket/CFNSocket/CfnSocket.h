//
//  CfnSocket.h
//  TSSocket
//
//  Created by tunsuy on 26/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^TSCallBack)(id result);

@interface CfnSocket : NSObject

- (void)loadDataFromServerWithServerDomain:(NSString *)serverDomain port:(int)port resultCallBack:(TSCallBack)callback;
- (void)loadDataFromServerWithHost:(NSString *)host port:(int)port resultCallBack:(TSCallBack)callback;

@end
