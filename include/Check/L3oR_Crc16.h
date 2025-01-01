#ifndef L3oR_CRC16_H
#define L3oR_CRC16_H

#include <stdint.h>

/**
 * @brief Initialize CRC16 calculation.
 * 
 * @return Returns the initial CRC value (0xFFFF).
 */
uint16_t Crc16_Init(void);

/**
 * @brief Update the CRC16 value with a single byte of data.
 * 
 * @param crc The current CRC value.
 * @param data A data byte to update the CRC value.
 * @return Returns the updated CRC value.
 */
uint16_t Crc16_Update(uint16_t crc, uint8_t data);

/**
 * @brief Continue CRC16 calculation with multiple bytes of data.
 * 
 * @param crc The current CRC value.
 * @param data Pointer to the data to update the CRC.
 * @param length The length of the data.
 * @return Returns the updated CRC value.
 */
uint16_t Crc16_Continue(uint16_t crc, uint8_t *data, uint16_t length);

/**
 * @brief Calculate the CRC16 for a given data array.
 * 
 * @param data Pointer to the data array.
 * @param length The length of the data array.
 * @return Returns the calculated CRC value.
 */
uint16_t Crc16_Calculate(uint8_t *data, uint16_t length);




#endif // L3oR_CRC16_H

