/**
 * @file
 * @license   ${PROJECT_LICENSE}
 * @copyright ${PROJECT_COPYRIGHT}
 * @version   ${PROJECT_VERSION}
 * @purpose   32-bit CRC calculation routines
 * @brief     32-bit CRC calculation routines
 */

#ifndef CRC32_H_
#define CRC32_H_

#include <stddef.h>
#include <stdint.h>

/** @defgroup crc32 CRC-32 calculation routines
 *  @code
 *  #include <embetech/crc32.h>
 *  @endcode
 *
 * This module groups utility functions that calculate 32-bit CRC.
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns POSIX cksum CRC32 initialization value.
 */
uint32_t CRC32_CKSUM_Init(void);

/**
 * Updates POSIX cksum CRC32 with a buffer of input data using the polynomial division formula.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value.
 */
uint32_t CRC32_CKSUM_UpdateFormulaIc(void const *in, size_t size, uint32_t crc);

/**
 * Updates POSIX cksum CRC32 with a buffer of input data using the Look-up-table.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value.
 */
uint32_t CRC32_CKSUM_UpdateLut(void const *in, size_t size, uint32_t crc);

/**
 * Finalizes the POSIX cksum CRC32 calculation.
 *
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value
 */
uint32_t CRC32_CKSUM_Finalize(uint32_t crc);

#ifdef __cplusplus
}
#endif

/** @} */

#endif
