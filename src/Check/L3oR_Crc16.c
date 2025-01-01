#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "Check/L3oR_Crc16.h"

/* Initialize CRC16 */
uint16_t Crc16_Init(void)
{
    return 0xFFFF;
}

/* Update CRC16 with a single byte of data */
uint16_t Crc16_Update(uint16_t crc, uint8_t data)
{
    crc ^= data;

    for (uint8_t i = 0; i < 8; i++)
    {
        if (crc & 0x0001) // If LSB is 1, XOR with 0xA001
            crc = (crc >> 1) ^ 0xA001;
        else
            crc >>= 1;
    }

    return crc;
}

/* Continue CRC16 calculation with multiple bytes of data */
uint16_t Crc16_Continue(uint16_t crc, uint8_t *data, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        crc = Crc16_Update(crc, data[i]);
    }

    return crc;
}

/* Calculate the CRC16 for a given data array */
uint16_t Crc16_Calculate(uint8_t *data, uint16_t length)
{
    return Crc16_Continue(Crc16_Init(), data, length);
}


// End of file
