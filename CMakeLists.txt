cmake_minimum_required(VERSION 3.25)

project(crc VERSION 1.0.1)
set(PROJECT_LICENSE "MIT License")
set(PROJECT_COPYRIGHT "Embetech sp. z o.o.")

option(CRC_TESTS "Configure unit tests target" ${PROJECT_IS_TOP_LEVEL})
option(CRC_DOC "Configure documentation target" ${PROJECT_IS_TOP_LEVEL})
option(CRC_EXAMPLES "Configure examples target" ${PROJECT_IS_TOP_LEVEL})
option(CRC_INSTALL "Configure install target" ON)

add_subdirectory(src)

if (CRC_TESTS)
  include(CTest)
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()

if (CRC_EXAMPLES)
  add_subdirectory(examples EXCLUDE_FROM_ALL)
endif ()

if (CRC_DOC)
  add_subdirectory(doc EXCLUDE_FROM_ALL)
endif ()

if (CRC_INSTALL)
  include(cmake/install.cmake)
endif ()
