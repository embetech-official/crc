#if __has_include(<embetech/embetile.h>) && EMBETILE_ENABLED // This macro is defined by invoking embetile_define_component
#    include <embetech/embetile.h>

#    ifndef EMBETILE_crc_ID
#        error "EMBETILE_crc_ID not defined"
#    endif

// Define embetile:        name,  id,               arch, verHi,  verLo,  revision
EMBETILE_DEFINE_HEADER(crc, EMBETILE_crc_ID, 0, CRC_VERSION_MAJOR, CRC_VERSION_MINOR, CRC_VERSION_PATCH)

EMBETILE_START_API()
EMBETILE_API_FUNC(CRC8_InitCRC)
EMBETILE_API_FUNC(CRC8_UpdateCRC_Byte)
EMBETILE_API_FUNC(CRC8_UpdateCRC_Buf)
EMBETILE_API_FUNC(CRC16_CCITT_InitCRC)
EMBETILE_API_FUNC(CRC16_CCITT_UpdateCRC_Byte)
EMBETILE_API_FUNC(CRC16_CCITT_UpdateCRC_Buf)
EMBETILE_API_FUNC(CRC16_CCITT_CheckCRC)
EMBETILE_API_FUNC(CRC16_MODBUS_InitCRC)
EMBETILE_API_FUNC(CRC16_MODBUS_UpdateCRC_Byte)
EMBETILE_API_FUNC(CRC16_MODBUS_UpdateCRC_Buf)
EMBETILE_API_FUNC(CRC16_MODBUS_CheckCRC)
EMBETILE_API_FUNC(CRC32_InitCRC)
EMBETILE_API_FUNC(CRC32_UpdateCRC_Buf)
EMBETILE_API_FUNC(CRC32_AppendToCRC)
EMBETILE_API_FUNC(CRC32_FinalizeCRC)
EMBETILE_END_API()
#else
typedef int make_iso_compiler_happy;
#endif