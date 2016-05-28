//
//  Connecter+ProtoInterface.h
//  TSSocket
//
//  Created by tunsuy on 25/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "Connecter.h"

@interface Connecter (ProtoInterface)

- (void)sayHello;
- (NSInteger)getTotolLengthOfPacket:(NSData *)orgData;
- (BOOL)analysisRecvPacketData:(NSMutableData *)data;

- (void)sendPacketWithSrvop:(NSInteger)srvop
                    andData:(NSData *)data
              andPacketType:(ePacketType)packetType
             andCallArgDict:(NSMutableDictionary *)callArgDict;

- (void)sendPacketWithSrvop:(NSInteger)srvop
                    andData:(NSData *)data
              andPacketType:(ePacketType)packetType
                   packetID:(NSNumber *)packetID
             andCallArgDict:(NSMutableDictionary *)callArgDict;

@end
