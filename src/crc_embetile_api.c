/**
 * @file
 * @license   ${PROJECT_LICENSE}
 * @copyright ${PROJECT_COPYRIGHT}
 * @version   ${PROJECT_VERSION}
 * @purpose   embeTILE API for CRC calculation routines
 * @brief     This file defines API calls that should be available as embeTILE calls when using embeTILE
 */

#if __has_include(<embetech/embetile.h>) && EMBETILE_ENABLED // This macro is defined by invoking embetile_define_component
#include <embetech/embetile.h>

#ifndef EMBETILE_crc_ID
#error "EMBETILE_crc_ID not defined"
#endif

// Define embetile:        name,  id,               arch, verHi,  verLo,  revision
EMBETILE_DEFINE_HEADER(crc, EMBETILE_crc_ID, 0, CRC_VERSION_MAJOR, CRC_VERSION_MINOR, CRC_VERSION_PATCH)

EMBETILE_START_API()
EMBETILE_API_FUNC(CRC8_ITU_Init)
EMBETILE_API_FUNC(CRC8_ITU_UpdateUsingLut)
EMBETILE_API_FUNC(CRC8_ITU_UpdateUsingFormula)
EMBETILE_API_FUNC(CRC8_ITU_Finalize)
EMBETILE_API_FUNC(CRC16_MODBUS_Init)
EMBETILE_API_FUNC(CRC16_MODBUS_UpdateUsingLut)
EMBETILE_API_FUNC(CRC16_MODBUS_UpdateUsingFormula)
EMBETILE_API_FUNC(CRC16_MODBUS_Finalize)
EMBETILE_API_FUNC(CRC16_CCITT_Init)
EMBETILE_API_FUNC(CRC16_CCITT_UpdateUsingLut)
EMBETILE_API_FUNC(CRC16_CCITT_UpdateUsingFormula)
EMBETILE_API_FUNC(CRC16_CCITT_Finalize)
EMBETILE_API_FUNC(CRC32_CKSUM_Init)
EMBETILE_API_FUNC(CRC32_CKSUM_UpdateUsingLut)
EMBETILE_API_FUNC(CRC32_CKSUM_UpdateUsingFormula)
EMBETILE_API_FUNC(CRC32_CKSUM_Finalize)
EMBETILE_END_API()
#else
typedef int make_iso_compiler_happy;
#endif
