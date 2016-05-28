//
//  ViewController.m
//  TSSocket
//
//  Created by tunsuy on 23/4/16.
//  Copyright © 2016年 tunsuy. All rights reserved.
//

#import "ViewController.h"
#import "BsdSocket.h"
#import "AsyncSocketService.h"
#import "CFNSocket/CfnSocket.h"
#import "NSStreamSocket/NSSocket.h"

static NSString *const serverDomain = @"svr.kd77.cn";
static int const port = 6800;

@interface ViewController ()

@property (nonatomic, strong) UILabel *hostLabel;
@property (nonatomic, strong) UILabel *portLabel;
@property (nonatomic, strong) UILabel *dataLabel;


@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    _hostLabel = [[UILabel alloc] initWithFrame:CGRectMake(40, 70, 150, 30)];
    _hostLabel.backgroundColor = [UIColor lightGrayColor];
    
    _portLabel = [[UILabel alloc] initWithFrame:CGRectMake(250, 70, 50, 30)];
    _portLabel.backgroundColor = [UIColor lightGrayColor];
    
    _dataLabel = [[UILabel alloc] initWithFrame:CGRectMake(40, 120, 240, 400)];
    _dataLabel.backgroundColor = [UIColor lightGrayColor];
    
    [self.view addSubview:_hostLabel];
    [self.view addSubview:_portLabel];
    [self.view addSubview:_dataLabel];
    
    UIBarButtonItem *bsdConnectBtn = [[UIBarButtonItem alloc] initWithTitle:@"BSD连接" style:UIBarButtonItemStyleDone target:self action:@selector(bsdConnectServer:)];
    UIBarButtonItem *asyncSocketConnectBtn = [[UIBarButtonItem alloc] initWithTitle:@"Asyn连接" style:UIBarButtonItemStyleDone target:self action:@selector(asyncSocketConnectServer:)];
    UIBarButtonItem *cfnSocketConnectBtn = [[UIBarButtonItem alloc] initWithTitle:@"CFN连接" style:UIBarButtonItemStyleDone target:self action:@selector(cfnSocketConnectServer:)];
    UIBarButtonItem *nsSocketConnectBtn = [[UIBarButtonItem alloc] initWithTitle:@"NSS连接" style:UIBarButtonItemStyleDone target:self action:@selector(nsSocketConnectServer:)];
    
    self.navigationItem.rightBarButtonItems = @[bsdConnectBtn, asyncSocketConnectBtn, cfnSocketConnectBtn, nsSocketConnectBtn];
    
}

- (void)bsdConnectServer:(UIBarButtonItem *)sender {
    BsdSocket *bsdSocket = [[BsdSocket alloc] init];
 
/** 域名连接 */
    [bsdSocket loadDataFromServerWithServerDomain:serverDomain port:port resultCallBack:^(id result){
        if ([result isKindOfClass:[NSString class]]) {
            NSString *errorMessage = [NSString stringWithFormat:@"%@", result];
            self.dataLabel.text = errorMessage;
            return;
        }
        if ([result isKindOfClass:[NSData class]]) {
            NSData *data = (NSData *)result;
            NSString *dataStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            self.dataLabel.text = dataStr;
            return;
        }
    }];
  
/** IP连接 */
//    [bsdSocket loadDataFromServerWithHost:@"200.200.169.165" port:port resultCallBack:^(id result){
//        if ([result isKindOfClass:[NSString class]]) {
//            NSString *errorMessage = [NSString stringWithFormat:@"%@", result];
//            self.dataLabel.text = errorMessage;
//            return;
//        }
//        if ([result isKindOfClass:[NSData class]]) {
//            NSData *data = (NSData *)result;
//            NSString *dataStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
//            self.dataLabel.text = dataStr;
//            return;
//        }
//    }];
}

//115.28.39.52
- (void)asyncSocketConnectServer:(UIBarButtonItem *)sender {
    AsyncSocketService *asyncSocketService = [[AsyncSocketService alloc] init];
    
/** 域名连接 */
//    [asyncSocketService connectToServerDomain:serverDomain onPort:port];
    
/** IP连接 */
    [asyncSocketService connectToHost:@"200.200.169.165" onPort:6800];
}

- (void)cfnSocketConnectServer:(UIBarButtonItem *)sender {
    CfnSocket *cfnSocket = [[CfnSocket alloc] init];
    
/** 域名连接 */
//    [cfnSocket loadDataFromServerWithServerDomain:serverDomain port:port resultCallBack:^(id result){
//        if ([result isKindOfClass:[NSMutableData class]]) {
//            NSData *data = (NSData *)result;
//            NSString *dataStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
//            self.dataLabel.text = dataStr;
//            return ;
//        }
//        if ([result isKindOfClass:[NSString class]]) {
//            NSString *errorInfo = [NSString stringWithFormat:@"%@", result];
//            self.dataLabel.text = errorInfo;
//            return;
//        }
//    }];
    
/** IP连接 */
    [cfnSocket loadDataFromServerWithHost:@"200.200.169.165" port:port resultCallBack:^(id result){
        if ([result isKindOfClass:[NSMutableData class]]) {
            NSData *data = (NSData *)result;
            NSString *dataStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            self.dataLabel.text = dataStr;
            self.dataLabel.numberOfLines = 0;
            return ;
        }
        if ([result isKindOfClass:[NSString class]]) {
            NSString *errorInfo = [NSString stringWithFormat:@"%@", result];
            self.dataLabel.text = errorInfo;
            self.dataLabel.numberOfLines = 0;
            return;
        }
    }];
}

- (void)nsSocketConnectServer:(UIBarButtonItem *)sender {
    NSSocket *nsSocket = [[NSSocket alloc] init];
    
    /** 域名连接 */
//    [nsSocket loadDataFromServerWithServerDomain:serverDomain port:port resultCallBack:^(id result){
//        if ([result isKindOfClass:[NSMutableData class]]) {
//            NSData *data = (NSData *)result;
//            NSString *dataStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
//            self.dataLabel.text = dataStr;
//            self.dataLabel.numberOfLines = 0;
//            return ;
//        }
//        if ([result isKindOfClass:[NSString class]]) {
//            NSString *errorInfo = [NSString stringWithFormat:@"%@", result];
//            self.dataLabel.text = errorInfo;
//            self.dataLabel.numberOfLines = 0;
//            return;
//        }
//        
//    }];

    /** IP连接 */
    [nsSocket loadDataFromServerWithHost:@"200.200.169.165" port:port resultCallBack:^(id result){
        if ([result isKindOfClass:[NSMutableData class]]) {
            NSData *data = (NSData *)result;
            NSString *dataStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            self.dataLabel.text = dataStr;
            self.dataLabel.numberOfLines = 0;
            return ;
        }
        if ([result isKindOfClass:[NSString class]]) {
            NSString *errorInfo = [NSString stringWithFormat:@"%@", result];
            self.dataLabel.text = errorInfo;
            self.dataLabel.numberOfLines = 0;
            return;
        }

    }];

}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
