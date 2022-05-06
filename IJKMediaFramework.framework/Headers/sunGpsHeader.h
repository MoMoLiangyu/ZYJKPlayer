//
//  sunGpsHeader.h
//  SunGps
//
//  Created by bobobobobo on 2017/12/11.
//  Copyright © 2017年 bobobobobo. All rights reserved.
//

#ifndef sunGpsHeader_h
#define sunGpsHeader_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _IPHONE_    1

#ifdef _WIN_
#include "../hbxTool/hbxList.h"
#define HBXLOG(fmt, ...)  TRACE( "HBXMP: " fmt, ##__VA_ARGS__)
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#endif

#ifdef _ANDROID_
#include "hbxList.h"
#define HBXLOG(fmt, ...)  __android_log_print(ANDROID_LOG_ERROR, HBX_LOG_TAG, fmt, ##__VA_ARGS__)
#endif

#ifdef _IPHONE_
#include "hbxList.h"
#define HBXLOG(fmt, ...) printf("HBXMP: " fmt, ##__VA_ARGS__)
#endif

struct STRSUN_INFO {
    char chInfoTag[4];
    unsigned int  nInfoLength;
    unsigned char chInfoByEncryption[124];
};

#define _DATABLOCK_MAX_  132
#define _DATAHEADER_MAX_ 20
#define _DATATAIL_MAX_   15

typedef long long(*SUNGPS_READCB)(unsigned char *, long long, int, int);


#define  _UCHAR_TO_UINT(chData,value) { \
value = chData[0]; \
value = (value << 8) + chData[1]; \
value = (value << 8) + chData[2]; \
value = (value << 8)  + chData[3]; \
}

#define  _UCHAR_TO_UINT_64_(chData,value) { \
value = chData[0]; \
value = (value << 8) + chData[1]; \
value = (value << 8) + chData[2]; \
value = (value << 8)  + chData[3]; \
value = (value << 8)  + chData[4]; \
value = (value << 8) + chData[5]; \
value = (value << 8) + chData[6]; \
value = (value << 8)  + chData[7]; \
}

#define  _UCHAR_TO_UINT_LIGO(chData,value) { \
value = chData[3]; \
value = (value << 8) + chData[2]; \
value = (value << 8) + chData[1]; \
value = (value << 8)  + chData[0]; \
}

#define  _LITTER_TO_BIG(litter,big) { \
big[0] = litter[3]; \
big[1] = litter[2]; \
big[2] = litter[1]; \
big[3] = litter[0]; \
}


#define  UINT_TO_UCHAR_(chData,value) { \
chData[0] = (value >> 24) & 0xff; \
chData[1] = (value >> 16) & 0xff; \
chData[2] = (value >> 8) & 0xff; \
chData[3] = value  & 0xff; \
}

#define RELEASE_BUFFER(buffer) if(buffer){ \
        free(buffer); \
        buffer = NULL; \
    } 


#endif /* sunGpsHeader_h */
