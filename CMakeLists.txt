cmake_minimum_required(VERSION 3.21)

project(crc LANGUAGES C VERSION 1.0.0)

option(CONFIG_CRC_TESTS "Configures test cases" ${PROJECT_IS_TOP_LEVEL})
option(CONFIG_CRC_INSTALL "Configures install target" ${PROJECT_IS_TOP_LEVEL})

include(requirements.cmake)

add_subdirectory(src)

if (CONFIG_CRC_TESTS)
  enable_testing()
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()
