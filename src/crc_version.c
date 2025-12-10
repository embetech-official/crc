#include <assert.h>
#include <embetech/crc.h>

#ifndef CRC_VERSION_MAJOR
#error "CRC_VERSION_MAJOR is not defined"
#endif

#ifndef CRC_VERSION_MINOR
#error "CRC_VERSION_MINOR is not defined"
#endif

#ifndef CRC_VERSION_PATCH
#error "CRC_VERSION_PATCH is not defined"
#endif

#ifndef CRC_COMMIT_ID
#error "CRC_COMMIT_ID is not defined"
#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define AS_HEX(x) AS_HEX_HELPER(x)
#define AS_HEX_HELPER(x) 0x##x

#if (0 == AS_HEX(CRC_COMMIT_ID))
#define CRC_COMMIT_ID_STR "local"
#else
#define CRC_COMMIT_ID_STR STR(CRC_COMMIT_ID)
#endif

static_assert(sizeof(CRC_COMMIT_ID_STR) <= 9, "CRC_COMMIT_ID_STR too long"); // NOLINT(readability-magic-numbers) - 8 chars + NUL

#define CRC_VERSION_STR STR(CRC_VERSION_MAJOR) "." STR(CRC_VERSION_MINOR) "." STR(CRC_VERSION_PATCH) "+" CRC_COMMIT_ID_STR

char const *CRC_GetVersionString(void) { return (CRC_VERSION_STR); }
