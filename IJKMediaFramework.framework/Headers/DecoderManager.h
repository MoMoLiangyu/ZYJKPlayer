//
//  PanoPlayerDisplayer.h
//  SGPlayer iOS
//
//  Created by huang on 2018/1/19.
//  Copyright © 2018年 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FishEyeHeader.h"

@protocol DecoderManagerDelegate <NSObject>

@optional
- (void)DecoderState:(int)state;
- (void)DecoderCurrent:(NSTimeInterval)current;

@end

@interface DecoderManager : NSObject

@property (assign, nonatomic, readonly) BOOL isPlaying;
/**
 * 是否是硬解码   默认NO
 */
@property (nonatomic, assign, readonly) BOOL isHardDecode;
/**
 * 是否使用TCP协议   默认NO
 */
@property (nonatomic, assign) BOOL tcpProtocol;

/// 是否镜像显示   默认NO
@property (assign, nonatomic) BOOL mirrorDisplay;

@property (nonatomic, weak) id<DecoderManagerDelegate> delegate;

+ (instancetype)shareDecoder;

- (void)layoutSubviews;

/**
 设置解码类型
 */
- (void)setHardDecode:(BOOL)hardDeocde;

/// 设置是否打开音频
/// @param buse 默认YES
- (void)setOriginalSound:(BOOL)buse;

/**
 播放普通预览流
 */
- (void)cameraPlay:(NSString *)path inView:(UIView *)view;

/**
 播放本地视频
 
 @param path 文件路径
 @param type 视频类型  1 http服务器和cam  2 预览页面rtsp/http 3.本地视频文件
 */
- (BOOL)cameraPlay:(NSString *)path type:(int)type inView:(UIView *)view;

/**
 播放记录仪在线视频或监控流

 @param path 文件地址
 @param fType 文件类型  1 http服务器和cam  2 预览页面rtsp/http 3.本地视频文件
 @param cType camera类型
 @param fishEyeId cameraID
 @param view 播放视频的载体
 */
- (void)cameraPlay:(NSString *)path fileType:(int)fType cameraType:(int)cType fishEyeId:(int)fishEyeId inView:(UIView *)view;

/**
 设置视频播放的样式
 
 @param mode 样式
 */
- (void)setDisplayMode:(DisplayMode)mode;
- (void)resum;
- (void)pause;
- (void)stop;

/// 清除画面
- (void)clearFrame;
- (int)status;
- (NSTimeInterval)current;
- (int)duration;
- (void)seekToTime:(NSTimeInterval)time;

/**
 检测沙盒中的Calibration
 */
- (void)checkCalibration:(NSString *)path;

/**
 初始化定点数据
 
 @param fileUrl 标定数据存放位置
 */
- (void)doInitFixed:(NSURL *)fileUrl;

/**
 保存ID到文件
 
 @param path 文件路径
 @param type 展开类型
 @param camId 摄像头ID
 */
- (void)saveIdToFile:(NSString *)path type:(int)type Id:(int)camId;

/**
 从文件中获取ID
 
 @param path 文件路径
 @return 获取ID
 */
- (NSArray *)getCamId:(NSString *)path;

/**
 更新定点数据
 */
- (void)updateFixed;

/**
 清空本地定点数据
 */
- (void)clearFixed;

/**
 获取calibration文件编码，用来更新calibration文件
 
 @return 编码
 */
- (int)getCalibrationId;

@end
