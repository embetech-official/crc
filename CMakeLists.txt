cmake_minimum_required(VERSION 3.25)

file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt" PROJECT_VERSION)
project(crc VERSION ${PROJECT_VERSION})

option(CRC_TESTS "Configure unit tests target" ${PROJECT_IS_TOP_LEVEL})
option(CRC_DOC "Configure documentation target" ${PROJECT_IS_TOP_LEVEL})
option(CRC_EXAMPLES "Configure examples target" ${PROJECT_IS_TOP_LEVEL})
option(CRC_INSTALL "Configure install target" ON)

include(cmake/requirements.cmake)

add_subdirectory(src)

if (CRC_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif ()

if (CRC_EXAMPLES)
  add_subdirectory(examples)
endif ()

if (CRC_DOC)
  add_subdirectory(doc)
endif ()

if (CRC_INSTALL)
  include(cmake/install.cmake)
endif ()
