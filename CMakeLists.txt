cmake_minimum_required(VERSION 3.21)

project(crc LANGUAGES C VERSION 1.0.0)

option(CONFIG_CRC_BUILD_TESTS "Forces building test cases" ${PROJECT_IS_TOP_LEVEL})

include(requirements.cmake)

add_subdirectory(src)

if (CONFIG_CRC_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif ()
