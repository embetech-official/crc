/**
 * @file
 * @license   ${PROJECT_LICENSE}
 * @copyright ${PROJECT_COPYRIGHT}
 * @version   ${PROJECT_VERSION}
 * @purpose   CRC calculation routines
 * @brief     CRC calculation routines
 */

#ifndef EMBETECH_CRC_H_
#define EMBETECH_CRC_H_

#include <embetech/semantic_version.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Returns CRC initialization value.
 */
uint8_t CRC8_ITU_Init(void);

/**
 * Updates ITU CRC8 with a buffer of input data using the polynomial division formula.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value.
 */
uint8_t CRC8_ITU_UpdateUsingFormula(void const *in, size_t size, uint8_t crc);

/**
 * Updates ITU CRC8 with a buffer of input data using the Look-up-table.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.

 * @return new CRC value.
 */
uint8_t CRC8_ITU_UpdateUsingLut(void const *in, size_t size, uint8_t crc);

/**
 * Finalizes the CRC.
 *
 * @param[in] crc current value of CRC.
 *
 * @return final CRC value.
 */
uint8_t CRC8_ITU_Finalize(uint8_t crc);

/**
 * Returns CCITT CRC16 initialization value for CCITT.
 */
uint16_t CRC16_CCITT_Init(void);

/**
 * Updates CCITT CRC16 with a buffer of input data using the Look-up-table.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.

 * @return new CCITT CRC16 value.
 */
uint16_t CRC16_CCITT_UpdateUsingLut(void const *in, size_t size, uint16_t crc);

/**
 * Updates CCITT CRC16 with a buffer of input data using the polynomial division formula.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.

 * @return new CCITT CRC16 value.
 */
uint16_t CRC16_CCITT_UpdateUsingFormula(void const *in, size_t size, uint16_t crc);

/**
 * Finalizes the CCITT CRC16.
 *
 * @param[in] crc current value of CRC.
 *
 * @return final CCITT CRC16 value.
 */
uint16_t CRC16_CCITT_Finalize(uint16_t crc);

/**
 * Returns MODBUS CRC16 initialization value for MODBUS.
 */
uint16_t CRC16_MODBUS_Init(void);

/**
 * Updates MODBUS CRC16 with a buffer of input data using the Look-up-table.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.

 * @return new MODBUS CRC16 value.
 */
uint16_t CRC16_MODBUS_UpdateUsingLut(void const *in, size_t size, uint16_t crc);

/**
 * Updates MODBUS CRC16 with a buffer of input data using the polynomial division formula.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.

 * @return new MODBUS CRC16 value.
 */
uint16_t CRC16_MODBUS_UpdateUsingFormula(void const *in, size_t size, uint16_t crc);

/**
 * Finalizes the MODBUS CRC16.
 *
 * @param[in] crc current value of CRC.
 *
 * @return final MODBUS CRC16 value.
 */
uint16_t CRC16_MODBUS_Finalize(uint16_t crc);

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
uint32_t CRC32_CKSUM_UpdateUsingFormula(void const *in, size_t size, uint32_t crc);

/**
 * Updates POSIX cksum CRC32 with a buffer of input data using the Look-up-table.
 *
 * @param[in] in input data buffer.
 * @param[in] size size of input data buffer (in bytes).
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value.
 */
uint32_t CRC32_CKSUM_UpdateUsingLut(void const *in, size_t size, uint32_t crc);

/**
 * Finalizes the POSIX cksum CRC32 calculation.
 *
 * @param[in] crc current value of CRC.
 *
 * @return new CRC value
 */
uint32_t CRC32_CKSUM_Finalize(uint32_t crc);

/**
 * @brief Get library version as a SemanticVersion structure.
 *
 * @return SemanticVersion value representing the library version.
 */
SemanticVersion CRC_GetVersion(void);

/**
 * @brief Get library version as a NUL-terminated string.
 *
 * @return Pointer to a read-only, statically-allocated string in semantic version format (e.g., "1.2.3"). Must not be freed or modified.
 */
char const *CRC_GetVersionString(void);

#ifdef __cplusplus
}
#endif

/** @} */

#endif
