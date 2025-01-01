#ifndef L3oR_BITMAP_H
#define L3oR_BITMAP_H

#include <stdint.h> // uint8_t

#ifdef __cplusplus
extern "C" {
#endif

#include "L3oR.h"

typedef struct {
	int iBitsSize;
	int iBytesSize;
	uint8_t *pByteArray;
} BitMap_st;


L3oR_API BitMap_st *BitMap_Create(int iBitsSize);
L3oR_API void BitMap_Free(BitMap_st *pBitMap);
L3oR_API int BitMap_Init(BitMap_st *pBitMap, uint8_t *pByteArray, int iBytesSize);
L3oR_API int BitMap_SetBit(BitMap_st *pBitMap, int iBitPos);
L3oR_API int BitMap_RstBit(BitMap_st *pBitMap, int iBitPos);
L3oR_API int BitMap_ReadBit(BitMap_st *pBitMap, int iBitPos);
L3oR_API int BitMap_SetBits(BitMap_st *pBitMap, int iPosStart, int iPosEnd);
L3oR_API int BitMap_RstBits(BitMap_st *pBitMap, int iPosStart, int iPosEnd);
L3oR_API int BitMap_GetFirstSet(BitMap_st *pBitMap);
L3oR_API int BitMap_GetFirstRst(BitMap_st *pBitMap);
L3oR_API int BitMap_GetCountSet(BitMap_st *pBitMap);
L3oR_API int BitMap_GetCountRst(BitMap_st *pBitMap);
L3oR_API int BitMap_GetBitsSize(BitMap_st *pBitMap);
L3oR_API int BitMap_GetBytesSize(BitMap_st *pBitMap);

#ifdef __cplusplus
}
#endif

#endif

// End of file
