# CRC

[![Unit Tests](https://github.com/embetech-official/crc/actions/workflows/unit_tests.yml/badge.svg)](https://github.com/embetech-official/crc/actions/workflows/unit_tests.yml)
![GitHub License](https://img.shields.io/github/license/embetech-official/crc)
![GitHub Release](https://img.shields.io/github/v/release/embetech-official/crc)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b8de2d81aca841dcb9f8c44d48c68b3e)](https://app.codacy.com/gh/embetech-official/crc/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=embetech-official_crc&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=embetech-official_crc)

## Overview
Ring Buffer is a library providing various Cyclic Redundancy Checksum calculation utilities

## Quick Start
The easiest way is to use built-in CMake FetchContent:

```cmake
include(FetchContent)
FetchContent_Declare(
    crc
    GIT_REPOSITORY https://github.com/embetech-official/crc
    GIT_TAG v1
)

FetchContent_MakeAvailable(crc)

# ...

target_link_libraries(<your target> PRIVATE embetech::crc)
``````
