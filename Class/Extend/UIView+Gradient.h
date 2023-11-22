//
//  UIView+Gradient.h
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Gradient)

/*
 *定义每个渐变颜色的CGColorRef对象数组
 *停止。默认为零。可设置动画
 */
@property(nullable, copy) NSArray *lx_colors;

/*
*NSNumber对象的可选阵列，定义每个
*梯度停止为[0,1]范围内的值。值必须为
*单调增加。如果给定nil数组，则停止为
*假设在[0,1]范围内均匀分布。当渲染时，
*颜色在
*插值。默认为零。可设置动画
*/
@property(nullable, copy) NSArray<NSNumber *> *lx_locations;


/*
*绘制到层中时渐变的起点和终点
*坐标空间。起点对应于第一个梯度
*停止，最后一个梯度停止的终点。这两点都是
*在单位坐标空间中定义，然后映射到
*绘制时图层的边界矩形。（即[0,0]是左下角
*层的角，[1,1]是右上角。）默认值
*分别为[.5，0]和[.5，1]。两者都可以设置动画
*/
@property CGPoint lx_startPoint;
@property CGPoint lx_endPoint;

//生成一个带渐变色的view
+ (UIView *_Nullable)lx_gradientViewWithColors:(NSArray<UIColor *> *_Nullable)colors locations:(NSArray<NSNumber *> *_Nullable)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint;

//给当前view设置渐变色
- (void)lx_setGradientBackgroundWithColors:(NSArray<UIColor *> *_Nullable)colors locations:(NSArray<NSNumber *> *_Nullable)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint;

@end

NS_ASSUME_NONNULL_END
