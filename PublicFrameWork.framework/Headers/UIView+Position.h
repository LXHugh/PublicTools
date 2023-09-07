//
//  UIView+Position.h
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Position)

@property (assign, nonatomic) CGFloat x;
@property (assign, nonatomic) CGFloat y;

@property (assign, nonatomic) CGFloat width;
@property (assign, nonatomic) CGFloat height;

@property (assign, nonatomic) CGPoint origin;
@property (assign, nonatomic) CGSize size;

@end

NS_ASSUME_NONNULL_END
