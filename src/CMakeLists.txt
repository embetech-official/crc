add_library(crc STATIC)
add_library(embetech::crc ALIAS crc)

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

if (PROJECT_IS_TOP_LEVEL)
  include(${PROJECT_SOURCE_DIR}/cmake/git_utils.cmake)
  get_git_commit_id(CRC_COMMIT_ID REQUIRED)
endif ()

if (NOT CRC_COMMIT_ID) # Fallback for out of tree builds
  set(CRC_COMMIT_ID 0)
endif ()

target_compile_definitions(
  crc PRIVATE CRC_VERSION_MAJOR=${PROJECT_VERSION_MAJOR} CRC_VERSION_MINOR=${PROJECT_VERSION_MINOR}
              CRC_VERSION_PATCH=${PROJECT_VERSION_PATCH} CRC_COMMIT_ID=${CRC_COMMIT_ID}
)

target_link_libraries(crc PUBLIC embetech::utils)

find_package(embetile QUIET)
if (embetile_FOUND)
  target_sources(crc PRIVATE crc_embetile_api.c)
  target_link_libraries(crc PRIVATE embetech::embetile)

  include(embetile_utils)
  embetile_make_available(crc)
endif ()
