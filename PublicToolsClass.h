//
//  PublicToolsClass.h
//  PublicTools
//
//  Created by 刘宣 on 2023/8/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PublicToolsClass : NSObject

#pragma mark -- view样式设置

#pragma mark -- 获取系统信息

#pragma mark -- 计算类方法

#pragma mark -- 加密方法
//MD5加密
+ (NSString *)md5Encryption:(NSString *)car;

@end

NS_ASSUME_NONNULL_END
