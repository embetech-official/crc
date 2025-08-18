# CRC

[![Unit Tests](https://github.com/embetech-official/crc/actions/workflows/unit_tests.yml/badge.svg)](https://github.com/embetech-official/crc/actions/workflows/unit_tests.yml)
![GitHub License](https://img.shields.io/github/license/embetech-official/crc)
![GitHub Release](https://img.shields.io/github/v/release/embetech-official/crc)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b8de2d81aca841dcb9f8c44d48c68b3e)](https://app.codacy.com/gh/embetech-official/crc/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=embetech-official_crc&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=embetech-official_crc)

## Overview
CRC is a C library to calculate 8/16/32- bit checksums using predefined polynomials

## Supported Polynomials
- CRC8-ITU (Poly 0x07, Init 0x00, no input/output bit reflection, XorOut 0x55)
- CRC16-CCITT BLUETOOTH CCITT-TRUE V-41-LSB KERMIT (Poly 0x1021, Init 0xFFFF, no input/output bit reflection, XorOut 0x0000)
- CRC16-MODBUS (Poly 0x8005, Init 0xFFFF, input/output bit reflection, XorOut 0x0000)
- CRC32-POSIX/cksum (Poly 0x04C11DB7, Init 0x00000000, no input/output bit reflection, XorOut 0xFFFFFFFF)


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
uitn16_t crc = CRC16_CCITT_Init();
crc = CRC16_CCITT_UpdateBuf(your_data, sizeof(your_data), crc);
crc = CRC16_CCITT_Finalize(crc);

// Manually append a byte to the checksum calculation
uint8_t additional_data = 0xaa;
uitn16_t crc2 = CRC16_CCITT_Init();
crc2 = CRC16_CCITT_UpdateBuf(your_data, sizeof(your_data), crc2);
crc2 = CRC16_CCITT_UpdateBuf(&additional_data, sizeof(additional_data), crc2);
crc2 = CRC16_CCITT_Finalize(crc);
```