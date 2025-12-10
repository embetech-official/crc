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

set_target_properties(crc PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

if (PROJECT_IS_TOP_LEVEL)
  # Retrieve the commit ID from the Git repository
  find_package(Git REQUIRED)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} -C ${CMAKE_SOURCE_DIR} rev-parse --short=8 HEAD
    OUTPUT_VARIABLE COMMIT_ID OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  message(VERBOSE "Commit ID: ${COMMIT_ID}")
else ()
  # Ingrown build. Do not use meaningful commit ID
  set(COMMIT_ID 0)
endif ()

target_compile_definitions(
  crc
  PRIVATE CRC_VERSION_MAJOR=${PROJECT_VERSION_MAJOR} CRC_VERSION_MINOR=${PROJECT_VERSION_MINOR}
          CRC_VERSION_PATCH=${PROJECT_VERSION_PATCH} CRC_VERSION_ID=0x${COMMIT_ID}
          CRC_VERSION=\"${PROJECT_VERSION}-${COMMIT_ID}\"
)

target_link_libraries(crc PUBLIC embetech::utils)

find_package(embetile QUIET)
if (embetile_FOUND)
  target_sources(crc PRIVATE crc_embetile_api.c)
  target_link_libraries(crc PRIVATE embetech::embetile)

  include(embetile_utils)
  embetile_make_available(crc)
endif ()
