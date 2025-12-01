#include <embetech/crc.h>

#ifndef CRC_VERSION_MAJOR
#define CRC_VERSION_MAJOR 0
#define CRC_VERSION_MINOR 0
#define CRC_VERSION_PATCH 0
#define CRC_VERSION_ID 0
#define CRC_VERSION "0.0.0-0"
#endif

SemanticVersion CRC_GetVersion(void) {
  return (SemanticVersion){.major = (CRC_VERSION_MAJOR), .minor = (CRC_VERSION_MINOR), .patch = (CRC_VERSION_PATCH), .id = (CRC_VERSION_ID)};
}

char const *CRC_GetVersionString(void) { return (CRC_VERSION); }
