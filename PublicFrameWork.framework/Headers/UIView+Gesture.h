//
//  UIView+Gesture.h
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^LXGestureRecognizerBlock)(UIView * view, UIGestureRecognizer * gesture);

typedef NS_ENUM(NSUInteger, LXGestureType) {
    LXGestureTypeTap,       // 点击
    LXGestureTypeDouble,    // 双击
    LXGestureTypeLongPress, // 长按
    LXGestureTypeSwipe,     // 轻扫
    LXGestureTypePan,       // 移动
    LXGestureTypeRotate,    // 旋转
    LXGestureTypePinch,     // 缩放
};

@interface UIView (Gesture)

///点击手势
///@param   block 手势响应回调
///@return  返回相应的手势
- (UIGestureRecognizer *)addTapGestureActionWithBlock:(LXGestureRecognizerBlock)block;

///手势处理
///@param   type     手势类型
///@param   block   手势响应回调
///@return  返回相应的手势
- (UIGestureRecognizer *)addGestureRecognizerWithType:(LXGestureType)type block:(LXGestureRecognizerBlock)block;

@end

NS_ASSUME_NONNULL_END
