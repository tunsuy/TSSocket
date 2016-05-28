//
//  Connecter+ProtoInterface.m
//  TSSocket
//
//  Created by tunsuy on 25/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "Connecter+ProtoInterface.h"
//#import "Srvhead.pb.h"

@implementation Connecter (ProtoInterface)

- (void)sendPacketWithSrvop:(NSInteger)srvop
                    andData:(NSData *)data
              andPacketType:(ePacketType)packetType
                   packetID:(NSNumber *)packetID
             andCallArgDict:(NSMutableDictionary *)callArgDict
{
    [self sendPacketWithSrvop:srvop andData:data andPacketType:packetType encrypt:YES packetID:packetID andCallArgDict:callArgDict];
}
- (void)sendPacketWithSrvop:(NSInteger)srvop
                    andData:(NSData *)data
              andPacketType:(ePacketType)packetType
                    encrypt:(BOOL)encrypt
                   packetID:(NSNumber *)packetID
             andCallArgDict:(NSMutableDictionary *)callArgDict


{
    NSAssert([callArgDict isKindOfClass:[NSMutableDictionary class]], nil);
//    if (self.disconnected) {
//        if(packetID) {
//            if(self.requests[packetID]) {
//                [self.requests removeObjectForKey:packetID];
//            }
//        }
//        NetCallback callback = callArgDict[@"callback"];
//        callArgDict[@"result"] = MOAErrorMake(kResultNetFailed, 0);
//        callArgDict[@"endDate"] = [NSDate date];
//        [MOANetManager netRecorderAddRecord:callArgDict];
//        if (callback) {
//            callback(self.chanID, nil, MOAErrorMake(kResultNetFailed, 0));
//        }
//        [self.lock unlock];
//        return;
//    }
    
//    if(callArgDict[@"retryInfo"] && data) {
//        NSAssert([callArgDict[@"retryInfo"] isKindOfClass:[NSMutableDictionary class]], nil);
//        NSAssert([data isKindOfClass:[NSData class]], nil);
//        callArgDict[@"retryInfo"][@"data"] = data;
//        callArgDict[@"retryInfo"][@"srvop"] = @(srvop);
//        callArgDict[@"retryInfo"][@"packetType"] = @(packetType);
//    }
//    
//    if(packetID == nil) {
//        packetID = @([self getAnUnusedPacketID]);
//        NSAssert(self.requests[packetID] == nil, nil);
//        self.requests[packetID] = callArgDict;
//    }
//    
//    PB_SrvHead_Builder *head;
//    head.srvop = srvop;
//    if (packetType == ePacketTypejson) {
//        head.flag = (head.flag | OPFLAG_JSON_DATA);
//    }
//    PB_ModMsgId *pbmmid = head.mmid;
//    pbmmid.clientReqId = [packetID integerValue];
//
//    UInt32 totolLenReal = 2+2+4+4+inString.length()+data.length;
//    
//    NSMutableData *sendData = [NSMutableData dataWithCapacity:totolLenReal];
//    
//    // 添加头部信息
//    char headBuf[kMinPacketLen];
//    char *p = headBuf;
//    *((UInt16 *)p) = htons(MERR_GET_SRV(srvop));
//    *((UInt16 *)(p+2)) = htons(0);
//    if (encrypt) {
//        NSMutableData *serverData = [NSMutableData dataWithBytesNoCopy:p length:2 freeWhenDone:NO];
//        [self translateData:serverData offset:0];
//        *((UInt16 *)(p)) = *((UInt16 *)serverData.bytes);
//        *((UInt16 *)(p+2)) = *((UInt16 *)(p+2)) | 0x200;
//    }else{
//        *((UInt16 *)(p+2)) = htons(0);
//    }
//    *((UInt32 *)(p+2+2)) = htonl(totolLenReal);
//    *((UInt32 *)(p+2+2+4)) = htonl(inString.length());
//    
//    [sendData appendBytes:headBuf length:kMinPacketLen];
//    [sendData appendBytes:inString.data() length:inString.length()];
//    [sendData appendBytes:data.bytes length:data.length];
//    // 加密数据体
//    if (encrypt) {
//        //NSLog(@"Key(%d):%@",self.seedData.length, self.seedData);
//        //NSLog(@"To send(%d):%@",sendData.length,  sendData);
//        [self translateData:sendData offset:kCryptPacketLenOffset];
//        //NSLog(@"After send(%d):%@",sendData.length,  sendData);
//    }
//    
//    [self sendPacket:sendData withPacketID:packetID.integerValue andTimeout:[callArgDict[@"timeout"] doubleValue]];
}

@end
