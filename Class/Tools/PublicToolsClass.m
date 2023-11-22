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
//设置单边圆角
+ (void)viewBeizerRect:(CGRect)rect view:(UIView *)view corner:(UIRectCorner)corner cornerRadii:(CGSize)radii {
    UIBezierPath *maskPath= [UIBezierPath bezierPathWithRoundedRect:rect byRoundingCorners:corner cornerRadii:radii];
    CAShapeLayer *maskLayer = [CAShapeLayer layer];
    maskLayer.frame =view.bounds;
    maskLayer.path = maskPath.CGPath;
    view.layer.mask = maskLayer;
}

//设置渐变色
+ (void)viewGradient:(UIView *)view stratColor:(UIColor *)sColor endColor:(UIColor *)eColor stratPoint:(CGPoint)sPoint endPoint:(CGPoint)ePoint {
    CAGradientLayer *layer = [CAGradientLayer layer];
    layer.frame = CGRectMake(0, 0, CGRectGetWidth(view.frame), CGRectGetHeight(view.frame));
    layer.colors = @[(__bridge  id)sColor.CGColor, (__bridge  id)eColor.CGColor];
    layer.startPoint = sPoint;
    layer.endPoint = ePoint;
    layer.locations = @[@0,@0.25,@0.5,@0.75,@1];
    [view.layer addSublayer:layer];
}

//view转换成image
+ (UIImage *)makeImageWithView:(UIView *)view withSize:(CGSize)size {
    //下面方法，第一个参数表示区域大小。第二个参数表示是否是非透明的。如果需要显示半透明效果，需要传NO，否则传YES。第三个参数就是屏幕密度了，关键就是第三个参数 [UIScreen mainScreen].scale。
    UIGraphicsBeginImageContextWithOptions(size, NO, [UIScreen mainScreen].scale);
    [view.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

//生成二维码
+ (UIImage *)QRCodeGenerate:(NSString*)codeUrl imageWidth:(CGFloat)imageW {
    
    // 1. 创建一个二维码滤镜实例(CIFilter)
    CIFilter *filter = [CIFilter filterWithName:@"CIQRCodeGenerator"];
    // 滤镜恢复默认设置
    [filter setDefaults];

    // 2. 给滤镜添加数据
    NSData *data = [codeUrl dataUsingEncoding:NSUTF8StringEncoding];
    [filter setValue:data forKeyPath:@"inputMessage"];

    // 3. 生成高清二维码
    CIImage *image = [filter outputImage];

    CGRect extent = CGRectIntegral(image.extent);
    CGFloat scale = MIN(imageW/CGRectGetWidth(extent), imageW/CGRectGetHeight(extent));
    // 1.创建bitmap;
    size_t width = CGRectGetWidth(extent) * scale;
    size_t height = CGRectGetHeight(extent) * scale;
    CGColorSpaceRef cs = CGColorSpaceCreateDeviceGray();
    CGContextRef bitmapRef = CGBitmapContextCreate(nil, width, height, 8, 0, cs, (CGBitmapInfo)kCGImageAlphaNone);
    CIContext *context = [CIContext contextWithOptions:nil];
    CGImageRef bitmapImage = [context createCGImage:image fromRect:extent];
    CGContextSetInterpolationQuality(bitmapRef, kCGInterpolationNone);
    CGContextScaleCTM(bitmapRef, scale, scale);
    CGContextDrawImage(bitmapRef, extent, bitmapImage);
    // 2.保存bitmap到图片
    CGImageRef scaledImage = CGBitmapContextCreateImage(bitmapRef);
    CGContextRelease(bitmapRef);
    CGImageRelease(bitmapImage);

    return [UIImage imageWithCGImage:scaledImage];
}





#pragma mark -- 计算类方法

//计算单行文字的文本宽度
+ (CGFloat)sizeWithText:(NSString *)text withFont:(UIFont *)font {
    CGSize size = [text sizeWithAttributes:@{NSFontAttributeName:font}];
    return size.width;
}

//计算文字的文本高度
+ (CGFloat)heightForLabel:(NSString *)text font:(UIFont *)font withLabelWidth:(CGFloat)width {
    CGSize size = [text boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:font} context:nil].size;
    return size.height;
}

//手机号中间四位变*
+ (NSString *)phoneNumberHiddenCenter:(NSString *)number {
    if (![self isPhoneNumber:number]) {
        return nil;
    }
    NSString *startStr = [number substringWithRange:NSMakeRange(0, 3)];
    NSString *endStr = [number substringWithRange:NSMakeRange(number.length-4, 4)];
    NSString *hiddenStr = [NSString stringWithFormat:@"%@****%@",startStr,endStr];
    return hiddenStr;
}

//字典转josn
+ (NSString *)convertToJsonData:(NSDictionary *)dict {
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dict
                                         options:NSJSONWritingSortedKeys
                                         error:&error];
    NSString *jsonString;
    if (!jsonData) {
        NSLog(@"字典转josn失败：%@",error);
    } else {
        jsonString = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    return jsonString;
}

//时间差值
+ (NSString *)getTotalTimeWithStartTime:(NSString *)startTime endTime:(NSString *)endTime withFormat:(NSString *)format {
    //按照日期格式创建日期格式句柄
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:format];
    NSTimeZone *localTimeZone = [NSTimeZone localTimeZone];
    [dateFormatter setTimeZone:localTimeZone];
    //将日期字符串转换成Date类型
    NSDate *startDate = [dateFormatter dateFromString:startTime];
    NSDate *endDate = [dateFormatter dateFromString:endTime];
    //将日期转换成时间戳
    NSTimeInterval start = [startDate timeIntervalSince1970]*1;
    NSTimeInterval end = [endDate timeIntervalSince1970]*1;
    NSTimeInterval value = end - start;
    //计算具体的天，时，分，秒
    int second = (int)value %60;//秒
    int minute = (int)value / 60 % 60;
    int house = (int)value / 3600;
    int day = (int)value / (24 * 3600);
    //将获取的int数据重新转换成字符串
    NSString *str;
    if (day != 0) {
        str = [NSString stringWithFormat:@"%d天%d小时%d分%d秒",day,house,minute,second];
    }else if (day==0 && house != 0) {
        str = [NSString stringWithFormat:@"%d小时%d分%d秒",house,minute,second];
    }else if (day== 0 && house== 0 && minute!=0) {
        str = [NSString stringWithFormat:@"%d分%d秒",minute,second];
    }else{
        str = [NSString stringWithFormat:@"%d秒",second];
    }
    //返回string类型的总时长
    return str;
}






#pragma mark -- 正则匹配
//邮箱
+ (BOOL)isValidateEmail:(NSString *)email {
    NSString  *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}" ;
    NSPredicate  *emailTest = [ NSPredicate   predicateWithFormat : @"SELF MATCHES%@",emailRegex];
    return  [emailTest  evaluateWithObject :email];
}

//手机号
+ (BOOL)isPhoneNumber:(NSString *)number {
    NSString *phoneRegex1=@"1[34578]([0-9]){9}";
    NSPredicate *phoneTest1 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",phoneRegex1];
    return  [phoneTest1 evaluateWithObject:number];
}

//身份证
+ (BOOL)isIdentityCard:(NSString *)IDCardNumber {
    if (IDCardNumber.length <= 0) {
        return NO;
    }
    NSString *regex2 = @"^(\\d{14}|\\d{17})(\\d|[xX])$";
    NSPredicate *identityCardPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",regex2];
    return [identityCardPredicate evaluateWithObject:IDCardNumber];
}

//银行卡
+ (BOOL)isBankCard:(NSString *)cardNumber {
    if(cardNumber.length==0) {
        return NO;
    }
    NSString *digitsOnly = @"";
    char c;
    for (int i = 0; i < cardNumber.length; i++) {
        c = [cardNumber characterAtIndex:i];
        if (isdigit(c)) {
            digitsOnly =[digitsOnly stringByAppendingFormat:@"%c",c];
        }
    }
    int sum = 0;
    int digit = 0;
    int addend = 0;
    BOOL timesTwo = false;
    for (NSInteger i = digitsOnly.length - 1; i >= 0; i--) {
        digit = [digitsOnly characterAtIndex:i] - '0';
        if (timesTwo) {
            addend = digit * 2;
            if (addend > 9) {
                addend -= 9;
            }
        }
        else {
            addend = digit;
        }
        sum += addend;
        timesTwo = !timesTwo;
    }
    int modulus = sum % 10;
    return modulus == 0;
}

//URL地址
+ (BOOL)isTrueUrl:(NSString *)webUrl {
    NSString *pattern = @"http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?";
    NSRegularExpression *regex = [[NSRegularExpression alloc] initWithPattern:pattern options:0 error:nil];
    NSArray *regexArray = [regex matchesInString:webUrl options:0 range:NSMakeRange(0, webUrl.length)];
    if (regexArray.count > 0) return YES; else return NO;
}

//去掉所有的特殊字符和标点符号
+ (NSString *)deleteCharacters:(NSString *)targetString {

    if (targetString.length == 0) {
        return @"";
    }

    NSError *error = nil;
    NSString *pattern = @"[^a-zA-Z0-9\u4e00-\u9fa5]";//正则取反
    NSRegularExpression *regularExpress = [NSRegularExpression regularExpressionWithPattern:pattern options:NSRegularExpressionCaseInsensitive error:&error];//这个正则可以去掉所有特殊字符和标点
    NSString *string = [regularExpress stringByReplacingMatchesInString:targetString options:0 range:NSMakeRange(0, [targetString length]) withTemplate:@""];

    return string;
}






#pragma mark -- 加密方法
//MD5加密
+ (NSString *)md5Encryption:(NSString *)car {
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
