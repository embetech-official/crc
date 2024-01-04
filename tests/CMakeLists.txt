project(crc_ut LANGUAGES CXX C)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)

FetchContent_Declare(
  googletest URL https://github.com/google/googletest/archive/main.zip FIND_PACKAGE_ARGS NAMES
                 GTest
)
FetchContent_MakeAvailable(googletest)

target_compile_options(
  crc
  PRIVATE -Werror
          -Wall
          -Wextra
          -Wpedantic
          -Wformat=2
          -Wformat-overflow=2
          -Wformat-security
          -Wformat-signedness
          -Wunused-parameter
          -Winit-self
          -Wcast-align
          -Wconversion
          -Wpedantic
          -Wnull-dereference
          -Wduplicated-cond
          -Wnull-dereference
          -Wsign-conversion
          -Wlogical-op
)

add_executable(crc_ut crc_ut.cpp)
target_link_libraries(crc_ut PRIVATE embetech::crc gtest_main)

include(GoogleTest)
gtest_discover_tests(crc_ut)
