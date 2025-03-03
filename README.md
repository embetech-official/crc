# CRC

[![Unit Tests](https://github.com/embetech-official/crc/actions/workflows/unit_tests.yml/badge.svg)](https://github.com/embetech-official/crc/actions/workflows/unit_tests.yml)
![GitHub License](https://img.shields.io/github/license/embetech-official/crc)
![GitHub Release](https://img.shields.io/github/v/release/embetech-official/crc)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b8de2d81aca841dcb9f8c44d48c68b3e)](https://app.codacy.com/gh/embetech-official/crc/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=embetech-official_crc&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=embetech-official_crc)

## Overview
CRC is a C library to calculate 8/16/32- bit checksums using predefined polynomials

## Supported Polynomials
- CRC8: X^8^+X^5^+X^4^+X^0^ (Naive)
- CRC16-CCITT (Naive, LUT)
- CRC16-MODBUS (Naive, LUT)
- CRC32-??? (LUT)


## Quick Start

In your CMakeLists.txt add: 
```cmake
include(FetchContent)
FetchContent_Declare( crc URL https://github.com/embetech-official/crc/archive/refs/tags/v1.zip)

# after your library/executable declaration:

FetchContent_MakeAvailable(crc)
target_link_libraries(<your target> PRIVATE embetech::crc)
``````

In your source files:
```c
#include <embetech/crc16.h>

uint8_t your_data[100] = {};

// checksum of buffer
uint16_t crc = CRC16_CCITT_UpdateBuf(your_data, sizeof(your_data),  CRC16_CCITT_Init());

// Manually append a byte to the checksum calculation
uint8_t other_byte = 42;
crc =  CRC16_CCITT_UpdateByte(other_byte, crc);
```