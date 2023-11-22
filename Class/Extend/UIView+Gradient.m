//
//  UIView+Gradient.m
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#import "UIView+Gradient.h"
#import <objc/runtime.h>

@implementation UIView (Gradient)

+ (Class)layerClass {
    return [CAGradientLayer class];
}

+ (UIView *)lx_gradientViewWithColors:(NSArray<UIColor *> *)colors locations:(NSArray<NSNumber *> *)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint {
    UIView *view = [[self alloc] init];
    [view lx_setGradientBackgroundWithColors:colors locations:locations startPoint:startPoint endPoint:endPoint];
    return view;
}

- (void)lx_setGradientBackgroundWithColors:(NSArray<UIColor *> *)colors locations:(NSArray<NSNumber *> *)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint {
    NSMutableArray *colorsM = [NSMutableArray array];
    for (UIColor *color in colors) {
        [colorsM addObject:(__bridge id)color.CGColor];
    }
    self.lx_colors = [colorsM copy];
    self.lx_locations = locations;
    self.lx_startPoint = startPoint;
    self.lx_endPoint = endPoint;
}

#pragma mark- Getter&Setter

- (NSArray *)lx_colors {
    return objc_getAssociatedObject(self, _cmd);
}

- (void)setLx_colors:(NSArray *)colors {
    objc_setAssociatedObject(self, @selector(lx_colors), colors, OBJC_ASSOCIATION_COPY_NONATOMIC);
    if ([self.layer isKindOfClass:[CAGradientLayer class]]) {
        [((CAGradientLayer *)self.layer) setColors:self.lx_colors];
    }
}

- (NSArray<NSNumber *> *)lx_locations {
    return objc_getAssociatedObject(self, _cmd);
}

- (void)setLx_locations:(NSArray<NSNumber *> *)locations {
    objc_setAssociatedObject(self, @selector(lx_locations), locations, OBJC_ASSOCIATION_COPY_NONATOMIC);
    if ([self.layer isKindOfClass:[CAGradientLayer class]]) {
        [((CAGradientLayer *)self.layer) setLocations:self.lx_locations];
    }
}

- (CGPoint)lx_startPoint {
    return [objc_getAssociatedObject(self, _cmd) CGPointValue];
}

- (void)setLx_startPoint:(CGPoint)startPoint {
    objc_setAssociatedObject(self, @selector(lx_startPoint), [NSValue valueWithCGPoint:startPoint], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if ([self.layer isKindOfClass:[CAGradientLayer class]]) {
        [((CAGradientLayer *)self.layer) setStartPoint:self.lx_startPoint];
    }
}

- (CGPoint)lx_endPoint {
    return [objc_getAssociatedObject(self, _cmd) CGPointValue];
}

- (void)setLx_endPoint:(CGPoint)endPoint {
    objc_setAssociatedObject(self, @selector(lx_endPoint), [NSValue valueWithCGPoint:endPoint], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    if ([self.layer isKindOfClass:[CAGradientLayer class]]) {
        [((CAGradientLayer *)self.layer) setEndPoint:self.lx_endPoint];
    }
}

@end

@implementation UILabel (Gradient)

+ (Class)layerClass {
    return [CAGradientLayer class];
}

@end
