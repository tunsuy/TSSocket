//
//  AsyncSocketService.h
//  TSSocket
//
//  Created by tunsuy on 25/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AsyncSocketService : NSObject

- (void)connectToServerDomain:(NSString *)serverDomain onPort:(NSUInteger)port;
- (void)connectToHost:(NSString *)host onPort:(NSUInteger)port;

@end
