include(GoogleTest)

add_executable(crc_ut)
target_sources(crc_ut PRIVATE crc_ut.cpp)

target_link_libraries(crc_ut PRIVATE embetech::crc GTest::gtest_main)

gtest_discover_tests(crc_ut)
