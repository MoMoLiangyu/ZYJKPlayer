//
//  PlayerDecoder.h
//  CameraPlayer
//
//  Created by Boris on 2017/2/22.
//  Copyright © 2017年 Boris. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    DecoderTypeMJPG,
    DecoderTypeH264,
    DecoderTypeUndifined,
} DecoderType;

typedef enum : NSUInteger {
    FilterTypeNone,
    FilterTypeBlur,
    //FilterTypeMirror,
    FilterTypeWatermark,
    //FilterTypeSplit4,
    FilterTypeBlack,
    //FiterTypeHFlip,
    FiterTypeHue,
    FiterTypeBox,
    FilterTypeNumber
} FilterType;

@class PlayerDecoder;
@protocol PlayerDecoderDelegate <NSObject>
- (void)decoder:(PlayerDecoder *)decoder didConnectingStream:(NSString *)url;
- (void)decoder:(PlayerDecoder *)decoder didStartReadingStream:(NSString *)url;
- (void)decoder:(PlayerDecoder *)decoder didExitWithError:(NSError *)error;

@optional
- (void)decoder:(PlayerDecoder *)decoder didFinishedScreenshot:(UIImage *)image;

@end

@protocol PlayerDecoderDataSource<NSObject>
- (NSMutableData *)videoDataForDecoder:(PlayerDecoder *)decoder;
@end

@interface PlayerDecoder : NSObject
@property (nonatomic, weak) id<PlayerDecoderDelegate> delegate;

- (instancetype)initWithCondition:(NSCondition *)condition collector:(NSMutableArray *)collector;
- (void)openStream:(NSString *)url;
- (void)openWithDataSource:(id<PlayerDecoderDataSource>)dataSource decoderType:(DecoderType)decoderType;
- (void)decodeFrameData:(NSData *)data decoderType:(DecoderType)decoderType;
- (void)closeStream;
- (void)screenshot;
- (void)addFilter:(FilterType)filterType waterMark:(NSString *)path;

@end
