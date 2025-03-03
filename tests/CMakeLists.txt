include(FetchContent)

FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/main.zip)

FetchContent_MakeAvailable(googletest)

add_executable(crc_ut crc_ut.cpp)
target_link_libraries(crc_ut PRIVATE embetech::crc gtest_main)

include(GoogleTest)
gtest_discover_tests(crc_ut)
