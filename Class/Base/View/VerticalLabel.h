//
//  VerticalLabel.h
//  PublicTools
//
//  Created by 刘宣 on 2023/12/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//垂直类型枚举
typedef enum{
    VerticalAlignmentTop = 0,   //置顶
    VerticalAlignmentMiddle,    //居中
    VerticalAlignmentBottom,    //底部
} VerticalAlignment;

@interface VerticalLabel : UILabel

//垂直参数
@property (nonatomic) VerticalAlignment verticalAlignment;

@end

NS_ASSUME_NONNULL_END
