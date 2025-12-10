#include <assert.h>
#include <embetech/crc.h>

#ifndef CRC_VERSION
#error "CRC_VERSION is not defined"
#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

static_assert(sizeof(CRC_VERSION) <= 64, "CRC_VERSION too long"); // NOLINT(readability-magic-numbers) - 8 chars + NUL

char const *CRC_GetVersionString(void) { return (CRC_VERSION); }
