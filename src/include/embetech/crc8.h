#ifndef CRC8_H_
#define CRC8_H_

#include <stdint.h>
#include <stddef.h>

uint8_t CRC8_InitCRC(void);

uint8_t CRC8_UpdateCRC_Byte(uint8_t byte, uint8_t crc);

uint8_t CRC8_UpdateCRC_Buf(const void *buf, size_t size, uint8_t crc);

#endif /* CRC8_H */
