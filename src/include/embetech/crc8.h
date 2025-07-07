/**
 * @file
 * @license   ${PROJECT_LICENSE}
 * @copyright ${PROJECT_COPYRIGHT}
 * @version   ${PROJECT_VERSION}
 * @purpose   8-bit CRC calculation routines
 * @brief     8-bit CRC calculation routines
 */

#ifndef CRC8_H_
#define CRC8_H_

#include <stddef.h>
#include <stdint.h>
/** @defgroup crc8 CRC-8 calculation routines
 *  @code
 *  #include <embetech/crc8.h>
 *  @endcode
 *
 * This module groups utility functions that calculate 8-bit CRC using a simple algorithm.
 *
 * @{*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns CRC initialization value.
 */
uint8_t CRC8_Init(void);

/**
 * Updates CRC with a single byte of input data.
 *
 * @param[in] byte byte of data.
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value.
 */
uint8_t CRC8_UpdateByte(uint8_t byte, uint8_t crc);

/**
 * Updates CRC with a buffer of input data using the CCITT algorithm.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.

 * @return new CRC value.
 */
uint8_t CRC8_UpdateBuf(void const *in, size_t size, uint8_t crc);

#ifdef __cplusplus
}
#endif

/** @} */

#endif
