//
//  PublicToolsClass.m
//  PublicTools
//
//  Created by 刘宣 on 2023/8/19.
//

#import "PublicToolsClass.h"

#import <CommonCrypto/CommonDigest.h>//MD5加密使用该库

@implementation PublicToolsClass

#pragma mark -- view样式设置

#pragma mark -- 获取系统信息

#pragma mark -- 计算类方法

#pragma mark -- 加密方法
//MD5加密
+ (NSString *)md5Encryption:(NSString *)car{
    const char *input = [car UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(input, (CC_LONG)strlen(input), result);
    NSMutableString *digest = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        [digest appendFormat:@"%02x", result[i]];
    }
    return digest;
}


@end
