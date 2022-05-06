//
//  SunGpsTool.h
//  SunGpsProtocol
//
//  Created by huang on 2017/12/13.
//  Copyright © 2017年 bobobobobo. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "sunGpsProtocol.h"
#import <CoreLocation/CoreLocation.h>

typedef void(^GpsResult)(NSArray *result);
@interface SunGpsTool : NSObject


+ (instancetype)shareTool;
/**
 获取视频中的gps数据

 @param url 视频地址(暂不支持ts流视频)
 @param block GPS数组
 */
- (void)getGpsInfo:(NSString *)url block:(GpsResult)block;

/**
同步获取视频中的gps数据
*/
- (NSArray *)getGpsInfo:(NSString *)url;

/**
 主要是针对http视频时，停止获取操作
 */
- (void)stopGetInfo;

- (int)getSunGpsDataVersion;

/**
 根据GPS信息判断是否在中国大陆

 @param lat 纬度
 @param lon 经度
 @return 结构
 */
- (BOOL)isInsideChina:(float)lat longitude:(float)lon;


/**
 国际标准转火星坐标

 @param location 国际标准gps
 @return 火星坐标GPS
 */
- (CLLocationCoordinate2D)wgs84ToGcj02:(CLLocationCoordinate2D)location;

/**
 火星坐标转国际标准

 @param location 火星坐标GPS
 @return 国际标准gps
 */
- (CLLocationCoordinate2D)gcj02ToWgs84:(CLLocationCoordinate2D)location;

@end
