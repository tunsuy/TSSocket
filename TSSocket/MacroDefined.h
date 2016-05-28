//
//  MacroDefined.h
//  TSSocket
//
//  Created by tunsuy on 25/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#ifndef MacroDefined_h
#define MacroDefined_h

#define TSErrorMakeOther(reason, other, num) [NSError errorWithDomain:@"customError" code:num userInfo:@{@"info":(reason), @"other":(other?other:[NSNull null]), @"ext":[NSString stringWithFormat:@"[%@:%d]", [[[NSString stringWithUTF8String:__FILE__] pathComponents] lastObject], __LINE__]}]

#endif /* MacroDefined_h */
