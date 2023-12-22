//
//  AutoRunLabel.h
//  PublicTools
//
//  Created by 刘宣 on 2023/12/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 指定滚动方向
typedef NS_ENUM(NSInteger, AutoScrollDirection) {
    AutoScrollDirectionRight,
    AutoScrollDirectionLeft
};

@interface AutoRunLabel : UIView<UIScrollViewDelegate>

@property (nonatomic) AutoScrollDirection scrollDirection;//滚动方向
@property (nonatomic) float scrollSpeed;// 滚动速度（像素/秒），默认为30
@property (nonatomic) NSTimeInterval pauseInterval; //暂停间隔 默认为1.5
@property (nonatomic) NSInteger labelSpacing; // 标签间距，默认为20
@property (nonatomic) CGFloat fadeLength; //淡入淡出长度 默认为7

/**
 *滚动UILabels时使用的动画选项。
 *@discussion UIViewAnimationOptionAllowUserInteraction始终应用于动画。
*/
@property (nonatomic) UIViewAnimationOptions animationOptions;

/**
 *如果它正在主动滚动，则返回YES；如果它已暂停或文本在范围内（禁用滚动），则返回NO。
*/
@property (nonatomic, readonly) BOOL scrolling;


// UILabel属性
@property (nonatomic, strong, nonnull) UIFont *font;
@property (nonatomic, copy, nullable) NSString *text;
@property (nonatomic, copy, nullable) NSAttributedString *attributedText;
@property (nonatomic, strong, nonnull) UIColor *textColor;
@property (nonatomic) NSTextAlignment textAlignment; // 仅在不自动滚动时适用
@property (nonatomic, strong, nullable) UIColor *shadowColor;
@property (nonatomic) CGSize shadowOffset;

/**
 *布局滚动视图内容，如果文本将被剪切，则启用文本滚动。
 *@discussion 在内部使用[scrollLabelIfNeeded]。
*/
- (void)refreshLabels;

/**
 *将文本设置为标签，并根据需要刷新标签。
 *@discussion 当您遇到需要在设置滚动标签的文本后对其进行布局的情况时很有用。
*/
- (void)setText:(nullable NSString *)text refreshLabels:(BOOL)refresh;

/**
如果需要，设置属性文本并刷新标签。
*/
- (void)setAttributedText:(nullable NSAttributedString *)theText refreshLabels:(BOOL)refresh;

/**
*如果标签宽度超过滚动视图的边界，则启动自动滚动。
*/
- (void)scrollLabelIfNeeded;

/**
 *观察UIApplication状态通知以自动重新启动滚动并监视
 *方向更改以刷新标签。
 *必须调用 @discussion 来观察通知。多次呼叫仍然只能注册一次通知。
*/
- (void)observeApplicationNotifications;

@end

NS_ASSUME_NONNULL_END
