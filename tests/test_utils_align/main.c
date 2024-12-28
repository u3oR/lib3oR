#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "Utils/L3oR_Align.h"

int main()
{
    /* msk */
    assert(L3oR_AlignMsk(4)  == 0x3U);
    assert(L3oR_AlignMsk(8)  == 0x7U);
    assert(L3oR_AlignMsk(16) == 0xFU);
    printf("L3oR_AlignMsk passed.\n");

    /* align up */
    assert(L3oR_AlignUp(0x13245670U, 4) == 0x13245670U); // 0b0000 -> 0b0000
    assert(L3oR_AlignUp(0x13245671U, 4) == 0x13245674U); // 0b0001 -> 0b0100
    assert(L3oR_AlignUp(0x13245672U, 4) == 0x13245674U); // 0b0010 -> 0b0100
    assert(L3oR_AlignUp(0x13245673U, 4) == 0x13245674U); // 0b0011 -> 0b0100
    assert(L3oR_AlignUp(0x13245670U, 8) == 0x13245670U); // 0b0000 -> 0b0000
    assert(L3oR_AlignUp(0x13245673U, 8) == 0x13245678U); // 0b0011 -> 0b1000
    assert(L3oR_AlignUp(0x13245677U, 8) == 0x13245678U); // 0b0111 -> 0b1000
    printf("L3oR_AlignUp passed.\n");

    /* align down */
    assert(L3oR_AlignDn(0x13245670U, 4) == 0x13245670U); // 0b0000 -> 0b0000
    assert(L3oR_AlignDn(0x13245671U, 4) == 0x13245670U); // 0b0001 -> 0b0000
    assert(L3oR_AlignDn(0x13245672U, 4) == 0x13245670U); // 0b0010 -> 0b0000
    assert(L3oR_AlignDn(0x13245677U, 4) == 0x13245674U); // 0b0111 -> 0b0100
    assert(L3oR_AlignDn(0x13245670U, 8) == 0x13245670U); // 0b0000 -> 0b0000
    assert(L3oR_AlignDn(0x13245673U, 8) == 0x13245670U); // 0b0011 -> 0b0000
    assert(L3oR_AlignDn(0x13245677U, 8) == 0x13245670U); // 0b0111 -> 0b0000
    printf("L3oR_AlignDn passed.\n");

    assert(L3oR_IsAligned(0x13245671UL, 4) == false);
    assert(L3oR_IsAligned(0x13245675UL, 4) == false);
    assert(L3oR_IsAligned(0x13245677UL, 4) == false);
    assert(L3oR_IsAligned(0x13245678UL, 4) == true);
    assert(L3oR_IsAligned(0x13245674UL, 4) == true);
    assert(L3oR_IsAligned(0x13245674UL, 8) == false);
    assert(L3oR_IsAligned(0x13245676UL, 8) == false);
    assert(L3oR_IsAligned(0x13245678UL, 8) == true);
    printf("L3oR_IsAligned passed.\n");

    return 0;
}
