//
//  sunGpsProtocol.h
//  SunGps
//
//  Created by on 2017/12/11.
//
#include "sunGpsHeader.h"

#ifndef sunGpsProtocol_h
#define sunGpsProtocol_h
int   SunSetEncType(int i);
int   SunGetEncType(void);
int   SunEncrypt(unsigned char *chInput,int inputlength,unsigned char *chOutput,int *outlength);
int   SunDecrypt(unsigned char *chInput,int inputlength,unsigned char *chOutput,int *outlength);
int   MakeHeader(char *output,int count);
int   MakeRawDataBlock(int nframe,char *chInfomation ,int chInfolength,unsigned char *chOutput);
int   MakeEncryptDataBlock(int nframe,char *chInfomation ,int chInfolength,unsigned char *chOutput);
int   SunDecodec(struct STRSUN_INFO *OutInfomation,unsigned char *chOutput,int *outlength);

#endif /* sunGpsProtocol_h */
