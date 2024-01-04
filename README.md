# CRC

[![C++ Unit Tests](https://github.com/embetech-official/crc/actions/workflows/cpp_unit_tests.yml/badge.svg)](https://github.com/embetech-official/crc/actions/workflows/cpp_unit_tests.yml)

## Overview
Ring Buffer is a library providing various Cyclic Reduncancy Checksum calculation utilities

## Installation
The easiest way is to use built-in CMake FetchContent:

```cmake
include(FetchContent)
FetchContent_Declare(
    crc
    GIT_REPOSITORY https://github.com/embetech-official/crc
    GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(crc)

# ...

target_link_libraries(<your target> PRIVATE embetech::crc)
``````
