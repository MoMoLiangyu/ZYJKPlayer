//
//  VideoCropper.h
//  SGPlayer iOS
//
//  Created by bobobobobo on 2019/11/13.
//  Copyright © 2019 single. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NSString *EditorFunctionKey NS_STRING_ENUM;

FOUNDATION_EXPORT EditorFunctionKey const EditorImageDataKey;
FOUNDATION_EXPORT EditorFunctionKey const EditorImageUrlKey;

NS_ASSUME_NONNULL_BEGIN

typedef void(^EditorBlock)(NSError *_Nullable error, id _Nullable arg);

@interface VideoEditor : NSObject


+ (instancetype)sharedInstance;

/**
 提取视频缩略图(压缩图)
 
 @param url 视频源地址
 @param markTime 标记需要获取缩略图的时间点
 @param block 缩略图结果回调
 */
- (void)extractThumbnail:(NSURL *)url markTime:(NSTimeInterval)markTime block:(EditorBlock)block;


/// 提取视频缩略图
/// @param url 视频源地址
/// @param markTime 标记需要获取缩略图的时间点
/// @param original 是否是原图
/// @param block 缩略图结果回调
- (void)extractThumbnail:(NSURL *)url markTime:(NSTimeInterval)markTime original:(BOOL)original block:(EditorBlock)block;

/**
 剪辑视频

 @param inPath 视频源地址
 @param outPath 视频输出地址
 @param timeRange 时间段
 @param origal 是否保留原音
 @param audioPath 合成其他音频的源地址,nil表示不合成
 */
+ (void)cropVideo:(NSString *)inPath outPath:(NSString *)outPath timeInterval:(NSRange)timeRange origalSound:(BOOL)origal audioPath:(nullable NSString *)audioPath block:(EditorBlock)block;

/**
剪辑视频

@param inPath 视频源地址
@param outPath 视频输出地址
@param timeRange 时间段
@param origal 是否保留原音
@param audioPath 合成其他音频的源地址,nil表示不合成
@param x264 是否需要将视频流转成H264
*/
+ (void)cropVideo:(NSString *)inPath outPath:(NSString *)outPath timeInterval:(NSRange)timeRange origalSound:(BOOL)origal audioPath:(NSString *)audioPath useLibx264:(BOOL)x264 block:(nonnull EditorBlock)block;


/**
 提取视频缩略图

 @param url 视频源地址
 @param markTime 标记需要获取缩略图的时间点
 @param block 缩略图结果回调
 */
+ (void)extractThumbnail:(NSString *)url markTime:(NSTimeInterval)markTime block:(EditorBlock)block;

/**
 提取视频总时长(本函数阻塞线程,需异步使用)

 @param url 视频源地址
 @return 视频时长
 */
+ (NSTimeInterval)extractVideoDuration:(NSURL *)url;

/**
将其他格式视频转成MP4

@param inPath 源地址
@param outPath 视频输出地址
*/
+ (void)transformVideo:(NSString *)inPath toMp4:(NSString *)outPath block:(EditorBlock)block;

/**
 将H264文件转成MP4
 
 @param inPath H264源地址
 @param outPath 视频输出地址
 */
+ (void)transformH264:(NSString *)inPath toVideo:(NSString *)outPath block:(EditorBlock)block;

/**
 将H264文件转成IMAGE
 
 @param inPath H264源地址
 @param outPath 图片输出地址
 */
+ (void)transformH264:(NSString *)inPath toImage:(NSString *)outPath block:(EditorBlock)block;

/**
 将多个JPEG文件转成MP4
 
 @param inDir JPEG所在文件夹
 @param outPath 视频输出地址
 @param fps 视频FPS
 */
+ (void)transformJpeg:(NSString *)inDir toVideo:(NSString *)outPath fps:(NSUInteger)fps block:(EditorBlock)block;

/**
 合成视频
 */
+ (void)mergeVideos:(NSArray *)files toVideo:(NSString *)outPath block:(EditorBlock)block;

@end

NS_ASSUME_NONNULL_END
