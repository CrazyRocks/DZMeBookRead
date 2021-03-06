//
//  DZMCoverController.h
//  DZMCoverDemo
//
//  Created by 邓泽淼 on 16/10/8.
//  Copyright © 2016年 DZM. All rights reserved.
//

/*
 
 可以用于小说覆盖翻页样式使用。 现在支持的是代理返回控制器 。
 
 Show Finder 该工程文件里面有 返回View的使用
 
 */

#import <UIKit/UIKit.h>

@class DZMCoverController;

@protocol DZMCoverControllerDelegate <NSObject>

@optional

/**
 *  切换是否完成
 *
 *  @param coverController   coverController
 *  @param currentController 当前正在显示的控制器
 *  @param isFinish          切换是否成功
 */
- (void)coverController:(DZMCoverController * __nonnull)coverController currentController:(UIViewController * __nullable)currentController finish:(BOOL)isFinish;

/**
 *  获取上一个控制器
 *
 *  @param coverController   coverController
 *  @param currentController 当前正在显示的控制器
 *
 *  @return 返回当前显示控制器的上一个控制器
 */
- (UIViewController * __nullable)coverController:(DZMCoverController * __nonnull)coverController getAboveControllerWithCurrentController:(UIViewController * __nullable)currentController;

/**
 *  获取下一个控制器
 *
 *  @param coverController   coverController
 *  @param currentController 当前正在显示的控制器
 *
 *  @return 返回当前显示控制器的下一个控制器
 */
- (UIViewController * __nullable)coverController:(DZMCoverController * __nonnull)coverController getBelowControllerWithCurrentController:(UIViewController * __nullable)currentController;

@end

@interface DZMCoverController : UIViewController

/**
 *  代理
 */
@property (nonatomic,weak,nullable) id<DZMCoverControllerDelegate> delegate;

/**
 *  手势启用状态 default:YES
 */
@property (nonatomic,assign) BOOL gestureRecognizerEnabled;

/**
 *  当前手势操作是否带动画效果 default: YES
 */
@property (nonatomic,assign) BOOL openAnimate;

/**
 *  当前控制器
 */
@property (nonatomic,strong,readonly,nullable) UIViewController *currentController;

/**
 *  手动设置显示控制器 无动画
 *
 *  @param controller 设置显示的控制器
 */
- (void)setController:(UIViewController * __nonnull)controller;

/**
 *  手动设置显示控制器
 *
 *  @param controller 设置显示的控制器
 *  @param animated   是否需要动画
 *  @param isAbove    动画是否从上面显示 YES   从下面显示 NO
 */
- (void)setController:(UIViewController * __nonnull)controller animated:(BOOL)animated isAbove:(BOOL)isAbove;

@end
