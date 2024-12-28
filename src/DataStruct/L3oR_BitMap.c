#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "Core/L3oR_Error.h"
#include "DataStruct/L3oR_BitMap.h"

BitMap_st *BitMap_Create(int iBitsSize)
{
	if (iBitsSize <= 0)
	{
		return NULL;
	}
	
	const int BITS_SIZE = iBitsSize;
	const int BYTES_SIZE = (BITS_SIZE + 7) / 8;
	const int BYTEARR_SIZE = sizeof(uint8_t) * BYTES_SIZE;

	BitMap_st *pBitMap = malloc(sizeof(BitMap_st));

	if (pBitMap == NULL)
	{
		return NULL;
	}

	memset(pBitMap, 0, sizeof(BitMap_st));

	pBitMap->pByteArray = malloc(BYTEARR_SIZE);

	if (pBitMap->pByteArray == NULL)
	{
		free(pBitMap);
		return NULL;
	}

	memset(pBitMap->pByteArray, 0, BYTEARR_SIZE);
		
	pBitMap->iBitsSize = BITS_SIZE;
	pBitMap->iBytesSize = BYTEARR_SIZE;
	
	return pBitMap;
}


int BitMap_Init(BitMap_st *pBitMap, uint8_t *pByteArray, int iBytesSize)
{
	if(pBitMap == NULL || pByteArray == NULL || iBytesSize <= 0)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	
	pBitMap->pByteArray = pByteArray;
	pBitMap->iBytesSize = iBytesSize;
	pBitMap->iBitsSize  = iBytesSize * 8;
	
	return L3oR_ERROR_NONE;
}

void BitMap_Free(BitMap_st *pBitMap)
{
    if (pBitMap != NULL)
    {
		if (pBitMap->pByteArray != NULL)
		{
			free(pBitMap->pByteArray);
		}
        free(pBitMap);
        pBitMap = NULL;
    }
}

static int BitMap_BitOperation(BitMap_st *pBitMap, int iBitPos, int iStat)
{
	if(pBitMap == NULL || iBitPos < 0 || iBitPos >= pBitMap->iBitsSize)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	
	const int iByteIndex = iBitPos / 8;
	const int iBitIndex  = iBitPos % 8;
	
	if(iStat){
		pBitMap->pByteArray[iByteIndex] |= (1 << iBitIndex);
		return 1;
	}else{
		pBitMap->pByteArray[iByteIndex] &= ~(1 << iBitIndex);
		return 0;
	}
}


int BitMap_SetBit(BitMap_st *pBitMap, int iBitPos)
{
	return BitMap_BitOperation(pBitMap, iBitPos, 1);
}


int BitMap_RstBit(BitMap_st *pBitMap, int iBitPos)
{
	return BitMap_BitOperation(pBitMap, iBitPos, 0);
}


int BitMap_ReadBit(BitMap_st *pBitMap, int iBitPos)
{
	if(pBitMap == NULL || iBitPos < 0 || iBitPos >= pBitMap->iBitsSize)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	
	const int iByteIndex = iBitPos / 8;
	const int iBitIndex  = iBitPos % 8;
	
	return (pBitMap->pByteArray[iByteIndex] >> iBitIndex) & 0x01U;	
}


static int BitMap_BitsOperation(BitMap_st *pBitMap, int iPosStart, int iPosEnd, int iStat)
{
	if( pBitMap == NULL || 
		iPosStart < 0 || iPosStart > iPosEnd || 
		iPosEnd >= pBitMap->iBitsSize )
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	
	for(int i = iPosStart; i <= iPosEnd; i++)
	{
		BitMap_BitOperation(pBitMap, i, iStat);
	}
	
	return (iStat != 0);
}


int BitMap_SetBits(BitMap_st *pBitMap, int iPosStart, int iPosEnd)
{
	return BitMap_BitsOperation(pBitMap, iPosStart, iPosEnd, 1);
}


int BitMap_RstBits(BitMap_st *pBitMap, int iPosStart, int iPosEnd)
{
	return BitMap_BitsOperation(pBitMap, iPosStart, iPosEnd, 0);
}


static int BitMap_FindFirstStat(BitMap_st *pBitMap, int iStat)
{
	if (pBitMap == NULL)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}

	for (int i = 0; i < pBitMap->iBitsSize; i++) 
	{
        if (iStat == BitMap_ReadBit(pBitMap, i)) 
		{
            return i;
        }
    }
    return L3oR_ERROR_UNSUPPORTED;
}


int BitMap_GetFirstSet(BitMap_st *pBitMap)
{
	if (pBitMap == NULL)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	return BitMap_FindFirstStat(pBitMap, 1);
}


int BitMap_GetFirstRst(BitMap_st *pBitMap)
{
	if (pBitMap == NULL)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}

	return BitMap_FindFirstStat(pBitMap, 0);
}


static int BitMap_CountStat(BitMap_st *pBitMap, int iStat)
{
	int iCount = 0;
	
	for (int i = 0; i < pBitMap->iBitsSize; i++) 
	{
        if (iStat == BitMap_ReadBit(pBitMap, i)) 
		{
            iCount++;
        }
    }
    return iCount;
}


int BitMap_GetCountSet(BitMap_st *pBitMap)
{
	return BitMap_CountStat(pBitMap, 1);
}


int BitMap_GetCountRst(BitMap_st *pBitMap)
{
	return BitMap_CountStat(pBitMap, 0);
}


int BitMap_GetBitsSize(BitMap_st *pBitMap)
{
	if(pBitMap == NULL)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	
	return pBitMap->iBitsSize;
}


int BitMap_GetBytesSize(BitMap_st *pBitMap)
{
	if(pBitMap == NULL)
	{
		return L3oR_ERROR_INVALID_PARAM;
	}
	
	return pBitMap->iBytesSize;
}


// End of file

