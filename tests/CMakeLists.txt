project(crc_ut LANGUAGES CXX C)

FetchContent_MakeAvailable(googletest)

add_executable(crc_ut crc_ut.cpp)
target_link_libraries(crc_ut PRIVATE embetech::crc gtest_main)

include(GoogleTest)
gtest_discover_tests(crc_ut)
