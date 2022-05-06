//
//  CameraPlayer.h
//  CameraPlayer
//
//  Created by Boris on 2017/2/22.
//  Copyright © 2017年 Boris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlayerDecoder.h"

typedef enum : NSUInteger {
    CameraPlayerStateConnecting,
    CameraPlayerStatePlaying,
    CameraPlayerStateStopped
} CameraPlayerState;

typedef enum : NSUInteger {
    StreamTypeMJPG,
    StreamTypeH264,
    StreamTypeUndifined,
} StreamType;


@class CameraPlayer;

@protocol CameraPlayerDelegate <NSObject>
- (void)player:(CameraPlayer *)player state:(CameraPlayerState)state error:(NSError *)error;
@optional
- (void)player:(CameraPlayer *)player screenFrameChanged:(UIView *)screenView;
- (void)player:(CameraPlayer *)player didFinishedScreenshot:(UIImage *)image;
- (void)player:(CameraPlayer *)player didFinishedSavingStream:(NSString *)path;

@end

@interface CameraPlayer : NSObject
@property (nonatomic, weak) id<CameraPlayerDelegate> delegate;
@property (readonly) BOOL playing;
@property (nonatomic, strong, readonly) UIView *screenView;

+ (BOOL)isStreamValid:(NSString *)url;
- (void)playLiveStream:(NSString *)url;
- (void)setLiveStreamView:(UIView *)liveView;
- (void)play:(NSString *)url inView:(UIView *)view;
- (void)playWithDataSource:(id<PlayerDecoderDataSource>)dataSource streamType:(StreamType)streamType inView:(UIView *)view;
- (void)decodeFrameData:(NSData *)data streamType:(StreamType)streamType;
- (void)stop;
- (void)clearScreen;
- (void)screenshot;
- (void)saveStream;
- (void)addFilter:(FilterType)filterType waterMark:(NSString *)path;

@end
