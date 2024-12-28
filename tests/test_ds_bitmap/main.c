#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Core/L3oR_Error.h"
#include "DataStruct/L3oR_BitMap.h"

void Test_BitMap_Create()
{
    BitMap_st *bitmap = BitMap_Create(16);

    assert(bitmap != NULL);
    assert(bitmap->iBitsSize == 16);
    assert(bitmap->iBytesSize == 2);
    memset(bitmap->pByteArray, 0xAA, 2);
    assert(bitmap->pByteArray[0] == 0xAA);

    BitMap_Free(bitmap); // 释放内存
    printf("Test_BitMap_Create passed.\n");
}

void Test_BitMap_Init()
{
    BitMap_st bitmap;
    uint8_t byteArray[4] = {0};

    int result = BitMap_Init(&bitmap, byteArray, sizeof(byteArray));
    assert(result == L3oR_ERROR_NONE);
    assert(bitmap.iBitsSize == 32);
    assert(bitmap.iBytesSize == 4);
    assert(bitmap.pByteArray == byteArray);

    printf("Test_BitMap_Init passed.\n");
}

void Test_BitMap_SetAndReadBit()
{
    BitMap_st bitmap;
    uint8_t byteArray[4] = {0};
    BitMap_Init(&bitmap, byteArray, sizeof(byteArray));

    BitMap_SetBit(&bitmap, 5);
    assert(BitMap_ReadBit(&bitmap, 4) == 0);
    assert(BitMap_ReadBit(&bitmap, 5) == 1);
    assert(BitMap_ReadBit(&bitmap, 6) == 0);

    BitMap_RstBit(&bitmap, 5);
    assert(BitMap_ReadBit(&bitmap, 5) == 0);

    printf("Test_BitMap_SetAndReadBit passed.\n");
}

void Test_BitMap_SetAndResetBits()
{
    BitMap_st bitmap;
    uint8_t byteArray[4] = {0};
    BitMap_Init(&bitmap, byteArray, sizeof(byteArray));

    BitMap_SetBits(&bitmap, 0, 15);
    for (int i = 0; i < 16; i++)
    {
        assert(BitMap_ReadBit(&bitmap, i) == 1);
    }
    for (int i = 16; i < 32; i++)
    {
        assert(BitMap_ReadBit(&bitmap, i) == 0);
    }

    BitMap_RstBits(&bitmap, 4, 7);
    for (int i = 0; i < 4; i++)
    {
        assert(BitMap_ReadBit(&bitmap, i) == 1);
    }
    for (int i = 4; i < 8; i++)
    {
        assert(BitMap_ReadBit(&bitmap, i) == 0);
    }

    printf("Test_BitMap_SetAndResetBits passed.\n");
}

void Test_BitMap_CountAndFind()
{
    BitMap_st bitmap;
    uint8_t byteArray[4] = {0};
    BitMap_Init(&bitmap, byteArray, sizeof(byteArray));

    BitMap_SetBits(&bitmap, 0, 3);
    BitMap_SetBits(&bitmap, 16, 19);

    assert(BitMap_GetCountSet(&bitmap) == 8);
    assert(BitMap_GetCountRst(&bitmap) == 24);

    int firstSet = BitMap_GetFirstSet(&bitmap);
    assert(firstSet == 0);
    int firstRst = BitMap_GetFirstRst(&bitmap);
    assert(firstRst == 4);

    printf("Test_BitMap_CountAndFind passed.\n");
}

void Test_BitMap_EdgeCases()
{
    // 测试空指针
    int result = BitMap_SetBit(NULL, 5);
    assert(result == L3oR_ERROR_INVALID_PARAM);

    result = BitMap_ReadBit(NULL, 5);
    assert(result == L3oR_ERROR_INVALID_PARAM);

    // 测试越界情况
    BitMap_st bitmap;
    uint8_t byteArray[2] = {0};
    BitMap_Init(&bitmap, byteArray, sizeof(byteArray));

    result = BitMap_SetBit(&bitmap, 16);
    assert(result == L3oR_ERROR_INVALID_PARAM);

    result = BitMap_ReadBit(&bitmap, -1);
    assert(result == L3oR_ERROR_INVALID_PARAM);

    printf("Test_BitMap_EdgeCases passed.\n");
}

int main()
{
    Test_BitMap_Create();
    Test_BitMap_Init();
    Test_BitMap_SetAndReadBit();
    Test_BitMap_SetAndResetBits();
    Test_BitMap_CountAndFind();
    Test_BitMap_EdgeCases();

    printf("All tests passed successfully.\n");
    return 0;
}
