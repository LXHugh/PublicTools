//
//  PublicFrameWork.h
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#import <Foundation/Foundation.h>

//! Project version number for PublicFrameWork.
FOUNDATION_EXPORT double PublicFrameWorkVersionNumber;

//! Project version string for PublicFrameWork.
FOUNDATION_EXPORT const unsigned char PublicFrameWorkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PublicFrameWork/PublicHeader.h>


/**
 全局对象
 @par MacroFrame   设计frame
 @par MacroObject   常用对象
 */
#import <PublicFrameWork/MacroFrame.h>
#import <PublicFrameWork/MacroObject.h>



/**
 常用的设计方法
 @par PublicToolsClass   公共类
 */
#import <PublicFrameWork/PublicToolsClass.h>



/**
 继承父类
 @par LBaseView   父类View
 @par LBaseViewController   父类VC
 @par LBaseNavigationController   父类navigation
 */
#import <PublicFrameWork/LBaseView.h>
#import <PublicFrameWork/LBaseViewController.h>
#import <PublicFrameWork/LBaseNavigationController.h>



/**
 扩展类
 @par UIView+Gesture    添加手势
 @par UIView+Gradient   渐变色
 @par UITextView+Placeholder    textView添加占位符
*/
#import <PublicFrameWork/UIView+Gesture.h>
#import <PublicFrameWork/UIView+Gradient.h>
#import <PublicFrameWork/UITextView+Placeholder.h>

