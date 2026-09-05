set(@PROJECT_NAME@_VERSION @PROJECT_VERSION@)

@PACKAGE_INIT@

######## MULTIARCH SELECTION ###########
# A packaged release bundles Release-only static libraries for every
# supported architecture side by side under lib/<arch>/, with one
# @PROJECT_NAME@-<arch>-targets.cmake per architecture next to this file.
# We include all of them, then alias the stable embetech::crc target to
# whichever architecture matches the consumer's toolchain (auto-detected, or
# overridden via CRC_ARCHITECTURE before find_package()).

include("${CMAKE_CURRENT_LIST_DIR}/detect_architecture_triplet.cmake")

if (NOT DEFINED CRC_ARCHITECTURE)
  detect_architecture_triplet(CRC_ARCHITECTURE)
  if (NOT CRC_ARCHITECTURE)
    message(FATAL_ERROR "Unable to auto-detect the target architecture for @PROJECT_NAME@. "
                         "Set CRC_ARCHITECTURE manually before calling find_package(@PROJECT_NAME@)."
    )
  endif ()
endif ()

message(DEBUG "CRC_ARCHITECTURE=${CRC_ARCHITECTURE}")

file(GLOB _crc_target_files "${CMAKE_CURRENT_LIST_DIR}/@PROJECT_NAME@-*-targets.cmake")
if (NOT _crc_target_files)
  message(FATAL_ERROR "No @PROJECT_NAME@ target files found in ${CMAKE_CURRENT_LIST_DIR}")
endif ()

set(_crc_available_architectures "")
foreach (_target_file IN LISTS _crc_target_files)
  include("${_target_file}")
  get_filename_component(_target_file_name "${_target_file}" NAME)
  string(REGEX REPLACE "^@PROJECT_NAME@-(.+)-targets\\.cmake$" "\\1" _target_arch "${_target_file_name}")
  list(APPEND _crc_available_architectures "${_target_arch}")
endforeach ()
unset(_crc_target_files)

if (NOT TARGET embetech::crc-${CRC_ARCHITECTURE})
  string(REPLACE ";" ", " _crc_available "${_crc_available_architectures}")
  message(FATAL_ERROR "@PROJECT_NAME@ was not built for architecture '${CRC_ARCHITECTURE}'. "
                       "Available architectures: ${_crc_available}"
  )
endif ()
unset(_crc_available_architectures)

add_library(embetech::crc ALIAS embetech::crc-${CRC_ARCHITECTURE})

######## MULTIARCH SELECTION END ###########

check_required_components("@PROJECT_NAME@")
