//
//  UIView+Gesture.m
//  PublicFrameWork
//
//  Created by 刘宣 on 2023/9/5.
//

#import "UIView+Gesture.h"
#import <objc/runtime.h>

static NSString * const _Nonnull LXGestureTypeStringMap[] = {
    [LXGestureTypeTap]       = @"UITapGestureRecognizer",
    [LXGestureTypeDouble]    = @"UITapGestureRecognizer",
    [LXGestureTypeLongPress] = @"UILongPressGestureRecognizer",
    [LXGestureTypeSwipe]     = @"UISwipeGestureRecognizer",
    [LXGestureTypePan]       = @"UIPanGestureRecognizer",
    [LXGestureTypeRotate]    = @"UIRotationGestureRecognizer",
    [LXGestureTypePinch]     = @"UIPinchGestureRecognizer",
};

@interface UIView ()

@property (nonatomic, strong) NSNumber *userInteractionNumbers;

@end

@implementation UIView (Gesture)

//单击手势
- (UIGestureRecognizer *)addTapGestureActionWithBlock:(LXGestureRecognizerBlock)block{
    return [self addGestureRecognizerWithType:LXGestureTypeTap block:block];
}

- (UIGestureRecognizer *)addGestureRecognizerWithType:(LXGestureType)type block:(LXGestureRecognizerBlock)block{
    self.userInteractionEnabled = YES;
    if (block) {
        NSString *string = LXGestureTypeStringMap[type];
        UIGestureRecognizer *gesture = [[NSClassFromString(string) alloc] initWithTarget:self action:@selector(category_gestureAction:)];
        [gesture setDelaysTouchesBegan:YES];
        [self addGestureRecognizer:gesture];
        if (type == LXGestureTypeTap) {
            [self.gestureRecognizers enumerateObjectsUsingBlock:^(__kindof UIGestureRecognizer *recognizer, NSUInteger idx, BOOL *stop) {
                if ([recognizer isKindOfClass:[UITapGestureRecognizer class]] && ((UITapGestureRecognizer*)recognizer).numberOfTapsRequired == 2) {
                    [gesture requireGestureRecognizerToFail:recognizer];
                    *stop = YES;
                }
            }];
            string = [string stringByAppendingString:@"Tap"];
        } else if (type == LXGestureTypeDouble) {
            [(UITapGestureRecognizer *)gesture setNumberOfTapsRequired:2];
            [self.gestureRecognizers enumerateObjectsUsingBlock:^(__kindof UIGestureRecognizer *recognizer, NSUInteger idx, BOOL *stop) {
                if ([recognizer isKindOfClass:[UITapGestureRecognizer class]] && ((UITapGestureRecognizer*)recognizer).numberOfTapsRequired == 1) {
                    [recognizer requireGestureRecognizerToFail:gesture];
                    *stop = YES;
                }
            }];
            string = [string stringByAppendingString:@"Double"];
        }
        self.selectorString = string;
        self.gesrureblock = block;
        return gesture;
    }
    return nil;
}

- (void)category_gestureAction:(UIGestureRecognizer *)gesture{
    NSString *string = NSStringFromClass([gesture class]);
    if ([gesture isKindOfClass:[UITapGestureRecognizer class]]) {
        if (((UITapGestureRecognizer *)gesture).numberOfTapsRequired == 1) {
            string = [string stringByAppendingString:@"Tap"];
        } else {
            string = [string stringByAppendingString:@"Double"];
        }
    }
    self.selectorString = string;
    self.gesrureblock(gesture.view, gesture);
}

#pragma mark - associated

- (NSString *)selectorString{
    return objc_getAssociatedObject(self, @selector(selectorString));
}
- (void)setSelectorString:(NSString *)selectorString{
    objc_setAssociatedObject(self, @selector(selectorString), selectorString, OBJC_ASSOCIATION_COPY_NONATOMIC);
}
- (LXGestureRecognizerBlock)gesrureblock{
    return (LXGestureRecognizerBlock)objc_getAssociatedObject(self, NSSelectorFromString(self.selectorString));
}
- (void)setGesrureblock:(LXGestureRecognizerBlock)gesrureblock{
    objc_setAssociatedObject(self, NSSelectorFromString(self.selectorString), gesrureblock, OBJC_ASSOCIATION_COPY_NONATOMIC);
}


@end
