//
//  MacroFrame.h
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#ifndef MacroFrame_h
#define MacroFrame_h


#endif /* MacroFrame_h */

//屏幕宽
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width

//屏幕高
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

//屏幕frame
#define SCREEN_FRAME [UIScreen mainScreen].bounds

//statusbar的高度
#define StatusbarHeight \
({\
    CGFloat height = 0.0;\
    if (@available(iOS 13.0, *)) {\
        CGFloat topHeight = [UIApplication sharedApplication].windows.firstObject.safeAreaInsets.top;\
        height = topHeight ? topHeight : 20.0;\
    }else {\
        height = [[UIApplication sharedApplication] statusBarFrame].size.height;\
    }\
    (height);\
})\

//底部安全高度
#define BottomHeight \
({\
    CGFloat height = 0.0;\
    if (@available(iOS 13.0, *)) {\
        NSSet *set = [UIApplication sharedApplication].connectedScenes;\
        UIWindowScene *windowScene = [set anyObject];\
        UIWindow *window = windowScene.windows.firstObject;\
        height = window.safeAreaInsets.bottom;\
    } else if (@available(iOS 11.0, *)) {\
        UIWindow *window = [UIApplication sharedApplication].windows.firstObject;\
        height = window.safeAreaInsets.bottom;\
    }\
    (height);\
})\

//navigation高度 (带statusbar)
#define NavigationHeight (StatusbarHeight + 44)

// View 坐标(x,y)和宽高(width,height)
#define L_X(v)                    (v).frame.origin.x
#define L_Y(v)                    (v).frame.origin.y
#define L_WIDTH(v)                (v).frame.size.width
#define L_HEIGHT(v)              (v).frame.size.height
#define L_MinX(v)                CGRectGetMinX((v).frame)
#define L_MinY(v)                CGRectGetMinY((v).frame)
#define L_MidX(v)                CGRectGetMidX((v).frame)
#define L_MidY(v)                CGRectGetMidY((v).frame)
#define L_MaxX(v)                CGRectGetMaxX((v).frame)
#define L_MaxY(v)                CGRectGetMaxY((v).frame)


//是否是手机
#define isIPhone ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)

//是否是iPad
#define isIPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

// 判断iPhone4系列
#define isIPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 判断iPhone5系列
#define isIPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 判断iPhone6系列
#define isIPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iphone6+系列
#define isIPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 判断iPhoneX
#define isIPhone_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 判断iPHoneXr | 11
#define isIPhone_Xr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 判断iPhoneXs | 11Pro
#define isIPhone_Xs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
// 判断iPhoneXs Max | 11ProMax
#define isIPhone_XsMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhone12_Mini
#define isIPhone12_Mini ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1080, 2340), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhone12 | 12Pro | 14
#define isIPhone12 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1170, 2532), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhone12 Pro Max | 14 Max
#define isIPhone12_ProMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1284, 2778), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhone14 pro
#define isIPhone14_Pro ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1179, 2556), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhone14 Pro Max
#define isIPhone14_ProMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1290, 2796), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
