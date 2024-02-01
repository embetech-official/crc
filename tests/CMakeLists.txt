project(crc_ut)

get_property(LANGUAGES GLOBAL PROPERTY ENABLED_LANGUAGES)
if (NOT CXX IN_LIST LANGUAGES)
  message(AUTHOR_ERROR "C++ support is required")
  return()
endif ()

cmake_policy(SET CMP0135 NEW)

include(FetchContent)

FetchContent_Declare(
  googletest URL https://github.com/google/googletest/archive/main.zip FIND_PACKAGE_ARGS NAMES
                 GTest
)
FetchContent_MakeAvailable(googletest)

add_executable(crc_ut crc_ut.cpp)
target_link_libraries(crc_ut PRIVATE embetech::crc gtest_main)

include(GoogleTest)
gtest_discover_tests(crc_ut)
