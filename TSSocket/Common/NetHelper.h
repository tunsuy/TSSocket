//
//  NetHelper.h
//  TSSocket
//
//  Created by tunsuy on 26/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NetHelper : NSObject

+ (NSString *)getIPWithHostName:(const NSString *)hostName;
+ (NSString *)lookupHostIPAddressForURL:(NSURL *)url;

@end
