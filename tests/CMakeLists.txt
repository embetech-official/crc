project(crc_ut LANGUAGES CXX C)

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
