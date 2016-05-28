//
//  Connecter.h
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import <Foundation/Foundation.h>

#define HEART_BEAT_INTERVAL     60.0

typedef enum : NSInteger {
    ePacketTypeProto = 0,
    ePacketTypejson,
} ePacketType;

typedef void (^NetCallback)(NSNumber* chanID, id result, NSError *error);

@class Connecter;

@protocol NetConnectProtocol <NSObject>
- (BOOL)socketShouldConsultAfterLink:(Connecter *)sock;
- (void)socketDidConnect:(Connecter *)sock;
- (void)socketDisconnect:(Connecter *)sock withError:(NSError *)error;
- (void)socket:(Connecter *)sock recvPushMsgOpr:(NSInteger)srvop andData:(NSData *)data andPacketType:(ePacketType)packetType;
@end

@interface Connecter : NSObject

@property (nonatomic, strong) NSString *ip;
@property (nonatomic) NSUInteger port;

@property (nonatomic) BOOL disconnected;
@property (nonatomic) NSUInteger currentPacketID;
@property (nonatomic, strong) NSMutableDictionary *requests;

- (instancetype)initWithIP:(NSString *)ip port:(uint16_t)port;
- (NSError *)connectedInTimeout:(NSTimeInterval)timeout;

- (NSUInteger)getAnUnusedPacketID;

@end
