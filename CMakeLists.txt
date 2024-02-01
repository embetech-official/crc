cmake_minimum_required(VERSION 3.28)

project(crc VERSION 1.0.0)

option(CRC_TESTS "Configure unit tests target" OFF)
option(CRC_DOC "Configure documentation target" OFF)
option(CRC_EXAMPLES "Configure examples target" OFF)
option(CRC_INSTALL "Configure install target" ON)

option(CRC_USE_LUT_16 "Use lookup table for 16-bit CRC calculation" ON)

add_subdirectory(src)

if (CRC_TESTS OR PROJECT_IS_TOP_LEVEL)
  enable_testing()
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()

if (CRC_EXAMPLES OR PROJECT_IS_TOP_LEVEL)
  add_subdirectory(examples EXCLUDE_FROM_ALL)
endif ()

if (CRC_DOC OR PROJECT_IS_TOP_LEVEL)
  add_subdirectory(doc EXCLUDE_FROM_ALL)
endif ()
