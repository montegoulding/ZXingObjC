/*
 * Copyright 2012 ZXing authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

@class ZXBitArray, ZXEncodeHints, ZXErrorCorrectionLevel, ZXMode, ZXQRCode;

extern const NSStringEncoding DEFAULT_BYTE_MODE_ENCODING;

@interface ZXEncoder : NSObject

+ (BOOL)encode:(NSString *)content ecLevel:(ZXErrorCorrectionLevel *)ecLevel qrCode:(ZXQRCode *)qrCode error:(NSError**)error;
+ (BOOL)encode:(NSString *)content ecLevel:(ZXErrorCorrectionLevel *)ecLevel hints:(ZXEncodeHints *)hints qrCode:(ZXQRCode *)qrCode error:(NSError**)error;
+ (int)alphanumericCode:(int)code;
+ (ZXMode *)chooseMode:(NSString *)content;
+ (BOOL)terminateBits:(int)numDataBytes bits:(ZXBitArray *)bits error:(NSError**)error;
+ (BOOL)numDataBytesAndNumECBytesForBlockID:(int)numTotalBytes numDataBytes:(int)numDataBytes numRSBlocks:(int)numRSBlocks blockID:(int)blockID numDataBytesInBlock:(int[])numDataBytesInBlock numECBytesInBlock:(int[])numECBytesInBlock error:(NSError**)error;
+ (BOOL)interleaveWithECBytes:(ZXBitArray *)bits numTotalBytes:(int)numTotalBytes numDataBytes:(int)numDataBytes numRSBlocks:(int)numRSBlocks result:(ZXBitArray *)result error:(NSError**)error;
+ (unsigned char *)generateECBytes:(unsigned char *)dataBytes numDataBytes:(int)numDataBytes numEcBytesInBlock:(int)numEcBytesInBlock;
+ (void)appendModeInfo:(ZXMode *)mode bits:(ZXBitArray *)bits;
+ (BOOL)appendLengthInfo:(int)numLetters version:(int)version mode:(ZXMode *)mode bits:(ZXBitArray *)bits error:(NSError**)error;
+ (BOOL)appendBytes:(NSString *)content mode:(ZXMode *)mode bits:(ZXBitArray *)bits encoding:(NSStringEncoding)encoding error:(NSError**)error;
+ (void)appendNumericBytes:(NSString *)content bits:(ZXBitArray *)bits;
+ (BOOL)appendAlphanumericBytes:(NSString *)content bits:(ZXBitArray *)bits error:(NSError**)error;
+ (void)append8BitBytes:(NSString *)content bits:(ZXBitArray *)bits encoding:(NSStringEncoding)encoding;
+ (BOOL)appendKanjiBytes:(NSString *)content bits:(ZXBitArray *)bits error:(NSError**)error;

@end
