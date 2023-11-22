//
//  MacroObject.h
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#ifndef MacroObject_h
#define MacroObject_h

#pragma mark - 沙盒

//获取沙盒 temp
#define PathTemp NSTemporaryDirectory()
//获取沙盒 Document
#define PathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define PathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//Document路径下文件/文件夹
#define DocumentPath(res) [PathDocument stringByAppendingPathComponent:res]
//Cache路径下文件/文件夹
#define CachePath(res) [PathCache stringByAppendingPathComponent:res]
//Temp路径下文件/文件夹
#define TempPath(res) [PathTemp stringByAppendingPathComponent:res]




#pragma mark - 颜色

// 颜色(RGB)
#define LRGB(r, g, b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define LRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

// 颜色(16进制)
#define LHexColor(hexValue) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 blue:((float)(hexValue & 0xFF)) / 255.0 alpha:1.0f]
#define LHexAlphaColor(hexValue, alpha) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 blue:((float)(hexValue & 0xFF)) / 255.0 alpha:alpha]

// 随机颜色
#define LRandomColor [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]




#pragma mark - 常用函数

//自定义Log
#ifdef DEBUG
    #define NSLog(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
    #define NSLog(FORMAT, ...) nil
#endif

//弱引用self（用于block块中）
#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self;

//载入Assets图片
#define LoctionImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]




#pragma mark- View设置

// View 圆角和加边框
#define ViewBorderRadius(view, Radius, Width, Color)\
\
[view.layer setCornerRadius:(Radius)];\
[view.layer setMasksToBounds:YES];\
[view.layer setBorderWidth:(Width)];\
[view.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(view, Radius)\
\
[view.layer setCornerRadius:(Radius)];\
[view.ayer setMasksToBounds:YES]

// View 阴影
#define ViewShadow(view, color, size, alpha, radius)\
\
view.layer.shadowColor = color.CGColor;\
view.layer.shadowOffset = size;\
view.layer.shadowOpacity = alpha;\
view.layer.shadowRadius = radius

// View 边框
#define ViewBorder(view, Color, Width)\
\
[view.layer setBorderWidth:(Width)];\
[view.layer setBorderColor:(Color).CGColor]



#pragma mark- 系统信息

// app名字
#define AppName (NSString *)[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]

// app版本号
#define AppVersion (NSString *)[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]

// app Build版本号
#define AppBuild (NSString *)[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

// 当前语言
#define CurrentLanguge ([[NSLocale preferredLanguages] objectAtIndex:0])

//手机序列号
#define IdentifierNumber [[UIDevice currentDevice] uniqueIdentifier]

//手机别名： 用户定义的名称
#define UserPhoneName [[UIDevice currentDevice] name]

//设备名称
#define DeviceName [[UIDevice currentDevice] systemName]

//手机系统版本
#define PhoneVersion [[UIDevice currentDevice] systemVersion]

//手机型号
#define PhoneModel [[UIDevice currentDevice] model]




#pragma mark- 判空
//字符串是否为空
#define IsNullString(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] <1? YES : NO )

//数组是否为空
#define IsNullArray(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0 || [array isEqual:[NSNull null]])

//字典是否为空
#define IsNullDict(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0|| [dic isEqual:[NSNull null]])

//是否是空对象
#define IsNullObject(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] ==0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] ==0))




#pragma mark- 持久化存储
//永久存储对象
#define SetUserDefaults(object, key) \
({ \
NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults]; \
[defaults setObject:object forKey:key]; \
[defaults synchronize]; \
})

//获取对象
#define GetUserDefaults(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]

//删除某一个对象
#define RemoveUserDefaults(key) \
({ \
NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults]; \
[defaults removeObjectForKey:_key]; \
[defaults synchronize]; \
})

//清除 NSUserDefaults 保存的所有数据
#define RemoveAllUserDefaults  [[NSUserDefaults standardUserDefaults] removePersistentDomainForName:[[NSBundle mainBundle] bundleIdentifier]]


//延迟执行
CG_INLINE void loadTime(CGFloat time ,dispatch_block_t block) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), block);
}

//回到主线程
CG_INLINE void runMain(dispatch_block_t block){
    dispatch_async(dispatch_get_main_queue(), block);
}

//只运行一次
CG_INLINE void runOnce(dispatch_block_t block){
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, block);
}

//开辟异步线程
CG_INLINE void runAsyn(dispatch_block_t block){
    dispatch_async(dispatch_get_global_queue(0, 0), block);
}

//获取添加了当前view视图的控制器
CG_INLINE UIViewController *superViewController(UIView *view){
    UIResponder *next = [view nextResponder];
    do{
        if([next isKindOfClass:[UIViewController class]]) {
            return(UIViewController*)next;
        }next = [next nextResponder];
    }while(next != nil);
    return nil;
}

//获取当前window展示的控制器
CG_INLINE UIViewController *currentViewController(){
    //获取当前活动窗口的根数图
    UIViewController *vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (1) {
        //根据不同的页面切换方式，逐步获取最上层的viewController
        if ([vc isKindOfClass:[UITabBarController class]]) {
            vc = ((UITabBarController *)vc).selectedViewController;
        }
        if ([vc isKindOfClass:[UINavigationController class]]) {
            vc = ((UINavigationController *)vc).visibleViewController;
        }
        if (vc.presentedViewController) {
            vc = vc.presentedViewController;
        }else {
            break;
        }
    }
    return vc;
}

#endif /* MacroObject_h */
