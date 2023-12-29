#ifndef CRC16_H_
#define CRC16_H_

#if defined __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/** \defgroup crc16 CRC 16 bit handling routines.
 *  \code
 *  #include <embetech/crc16.h>
 *  \endcode
 *
 * This module groups utility functions that calculate 16-bit CRC using various
 * algorithms. Currently CCITT and MODBUS algorithms are supported.
 *
 * @{*/

#ifndef CRC16_CCITT_USE_LUT
/**
 * This definition enables (1) or disables (0) look-up table usage for CCITT
*/
#define CRC16_CCITT_USE_LUT					1
#endif

#ifndef CRC16_MODBUS_USE_LUT
/**
 * This definition enables (1) or disables (0) look-up table usage for MODBUS
*/
#define CRC16_MODBUS_USE_LUT					0
#endif


/**
 * Returns CRC initialization value for CCITT
*/
uint16_t CRC16_CCITT_InitCRC(void);

/**
 * Updates CRC with a single byte of input data using the CCITT algorithm.
 *
 * \param byte byte of data
 * \param crc current value of CRC
 *
 * \return new CRC value
*/
uint16_t CRC16_CCITT_UpdateCRC_Byte(uint8_t byte, uint16_t crc);

/**
 * Updates CRC with a buffer of input data using the CCITT algorithm.
 *
 * \param buf input data buffer
 * \param size size of input data buffer (in bytes)
 *
 * \return new CRC value
*/
uint16_t CRC16_CCITT_UpdateCRC_Buf(const void *buf, size_t size, uint16_t crc);

/**
 * Checks CRC validity for a buffer of data by calculating the CRC and comparing it
 * to a given value. Is uses the CCITT algorithm.
 *
 * \param buf input buffer
 * \param size size of the input buffer (in bytes)
 * \param crc expected CRC
 *
 * \return 1 is CRC matches (OK!)
 *         0 if the calculated CRC does not match the given value (CRC ERROR!)
 *
*/
int CRC16_CCITT_CheckCRC(const void *buf, size_t size, uint16_t crc);

/**
 * Returns CRC initialization value for MODBUS
*/
uint16_t CRC16_MODBUS_InitCRC(void);

/**
 * Updates CRC with a single byte of input data using the MODBUS algorithm.
 *
 * \param byte byte of data
 * \param crc current value of CRC
 *
 * \return new CRC value
*/
uint16_t CRC16_MODBUS_UpdateCRC_Byte(uint8_t byte, uint16_t crc);

/**
 * Updates CRC with a buffer of input data using the MODBUS algorithm.
 *
 * \param buf input data buffer
 * \param size size of input data buffer (in bytes)
 *
 * \return new CRC value
*/
uint16_t CRC16_MODBUS_UpdateCRC_Buf(const void *buf, size_t size, uint16_t crc);

/**
 * Checks CRC validity for a buffer of data by calculating the CRC and comparing it
 * to a given value. Is uses the MODBUS algorithm.
 *
 * \param buf input buffer
 * \param size size of the input buffer (in bytes)
 * \param crc expected CRC
 *
 * \return 1 is CRC matches (OK!)
 *         0 if the calculated CRC does not match the given value (CRC ERROR!)
 *
*/
int CRC16_MODBUS_CheckCRC(const void *buf, size_t size, uint16_t crc);

/** @} */

/*! \file crc16.h
    \brief 16-bit CRC calculation routines
*/

#if defined __cplusplus
} // extern "C"
#endif

#endif // CRC16_H
