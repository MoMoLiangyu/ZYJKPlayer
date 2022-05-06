//
//  VideoFramePlayer.h
//  IJKMediaFramework
//
//  Created by sunningsoft on 2020/8/6.
//  Copyright © 2020 bilibili. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    MediaCodecH264,
    MediaCodecMJPEG,
} MediaCodec;

@interface VideoFramePlayer : NSObject

- (void)playRealTimeStreamInView:(UIView *_Nullable)view codec:(MediaCodec)codec;
- (void)stopToPlayRealTimeStream;
- (void)decodeNalu:(uint8_t *)frame withSize:(uint32_t)frameSize;
- (void)showMjpeg:(uint8_t *)frame withSize:(uint32_t)frameSize;

@end

NS_ASSUME_NONNULL_END
