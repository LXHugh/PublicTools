//
//  PublicToolsClass.h
//  PublicTools
//
//  Created by 刘宣 on 2023/8/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PublicToolsClass : NSObject

#pragma mark -- view样式设置
/**
 设置单边圆角
 @par rect 视图位置大小
 @par view 需要设置的视图
 @par corner 设置的对应边角
 @par radii 圆角尺寸
 */
+ (void)viewBeizerRect:(CGRect)rect view:(UIView *)view corner:(UIRectCorner)corner cornerRadii:(CGSize)radii;

/**
 生成二维码图片
 @par codeUrl   链接
 @par imageW 图片宽度
 @return 二维码图片
*/
+(UIImage *)QRCodeGenerate:(NSString*)codeUrl imageWidth:(CGFloat)imageW;







#pragma mark -- 计算类方法
//计算单行文字的文本宽度
+ (CGFloat)sizeWithText:(NSString *)text withFont:(UIFont *)font;

//计算文字的文本高度
+ (CGFloat)heightForLabel:(NSString *)text font:(UIFont *)font withLabelWidth:(CGFloat)width;

//手机号中间四位变*
+ (NSString *)phoneNumberHiddenCenter:(NSString *)number;

//字典转josn
+ (NSString *)convertToJsonData:(NSDictionary *)dict;

/**
 时间差值
 @par startTime     开始的时间
 @par endTime      结束的时间
 @par format          时间字符串的格式
 @return x天x小时x分x秒
 */
+ (NSString *)getTotalTimeWithStartTime:(NSString *)startTime endTime:(NSString *)endTime withFormat:(NSString *)format;









#pragma mark -- 正则匹配
//邮箱
+ (BOOL)isValidateEmail:(NSString *)email;

//手机号
+ (BOOL)isPhoneNumber:(NSString *)number;

//身份证
+ (BOOL)isIdentityCard:(NSString *)IDCardNumber;

//银行卡
+ (BOOL)isBankCard:(NSString *)cardNumber;

//URL地址
+ (BOOL)isTrueUrl:(NSString *)webUrl;

//去掉所有的特殊字符和标点符号
+ (NSString *)deleteCharacters:(NSString *)targetString;








#pragma mark -- 加密方法
//MD5加密
+ (NSString *)md5Encryption:(NSString *)car;

@end

NS_ASSUME_NONNULL_END
