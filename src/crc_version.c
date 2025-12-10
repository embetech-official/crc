#include <embetech/crc.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define AS_HEX(x) AS_HEX_HELPER(x)
#define AS_HEX_HELPER(x) 0x##x

#ifndef CRC_VERSION_MAJOR
#error "CRC_VERSION_MAJOR is not defined"
#endif

#ifndef CRC_VERSION_MINOR
#error "CRC_VERSION_MINOR is not defined"
#endif

#ifndef CRC_VERSION_PATCH
#error "CRC_VERSION_PATCH is not defined"
#endif

#if (!defined CRC_COMMIT_ID) || (0 == AS_HEX(CRC_COMMIT_ID))
#define CRC_COMMIT_ID_STR "local"
#else
#define CRC_COMMIT_ID_STR STR(CRC_COMMIT_ID)
#endif

#define CRC_VERSION STR(CRC_VERSION_MAJOR) "." STR(CRC_VERSION_MINOR) "." STR(CRC_VERSION_PATCH) "-" CRC_COMMIT_ID_STR

SemanticVersion CRC_GetVersion(void) {
  return (SemanticVersion){.major = (CRC_VERSION_MAJOR), .minor = (CRC_VERSION_MINOR), .patch = (CRC_VERSION_PATCH), .id = AS_HEX(CRC_COMMIT_ID)};
}

char const *CRC_GetVersionString(void) { return (CRC_VERSION); }
