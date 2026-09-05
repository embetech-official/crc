add_library(crc STATIC)
add_library(embetech::crc ALIAS crc)

target_compile_features(crc PRIVATE c_std_99)

target_sources(
  crc
  PRIVATE crc16.c crc32.c crc8.c crc_version.c
  PUBLIC FILE_SET
         HEADERS
         BASE_DIRS
         include
         FILES
         include/embetech/crc.h
         include/embetech/crc8.h
         include/embetech/crc16.h
         include/embetech/crc32.h
)

include(${PROJECT_SOURCE_DIR}/cmake/versioning.cmake)
get_version_string(CRC_VERSION_STRING VERSION ${PROJECT_VERSION})

target_compile_definitions(crc PRIVATE CRC_VERSION="${CRC_VERSION_STRING}")

find_package(embetile QUIET)
if (embetile_FOUND)
  target_sources(crc PRIVATE crc_embetile_api.c)
  target_link_libraries(crc PRIVATE embetech::embetile)

  include(embetile_utils)
  embetile_make_available(crc)
endif ()
