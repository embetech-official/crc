#ifndef CRC32_H_
#define CRC32_H_

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup crc32 CRC 32 bit handling routines.
 *  \code
 *  #include <embetech/crc32.h>
 *  \endcode
 *
 * This module groups utility functions that calculate 32-bit CRC.
 *
 * @{
 */

/**
 * Returns CRC initialization value.
 */
uint32_t CRC32_InitCRC(void);

/**
 * Updates CRC with a buffer of input data and finalizes the CRC calculation.
 *
 * \param buf input data buffer
 * \param size size of input data buffer (in bytes)
 * \param crc current value of CRC
 *
 * \return new CRC value
*/
uint32_t CRC32_UpdateCRC_Buf(const void *buffer, size_t size, uint32_t crc);

/**
 * Updates CRC with a buffer of input data without finalizing the CRC calculation.
 *
 * \param buf input data buffer
 * \param size size of input data buffer (in bytes)
 * \param crc current value of CRC
 *
 * \return new CRC value
*/
uint32_t CRC32_AppendToCRC(const void *buffer, size_t size, uint32_t crc);

/**
 * Finalizes the CRC calculation.
 * \param crc current value of CRC
 *
 * \return new CRC value
 */
uint32_t CRC32_FinalizeCRC(uint32_t crc);

/** @} */

/*! \file crc32.h
    \brief 32-bit CRC calculation routines
*/

#ifdef __cplusplus
}
#endif

#endif // CRC32_H
