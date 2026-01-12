# CRC

[![CI Tests](https://github.com/embetech-official/crc/actions/workflows/on_push.yml/badge.svg)](https://github.com/embetech-official/crc/actions/workflows/on_push.yml)
![GitHub License](https://img.shields.io/github/license/embetech-official/crc)
![GitHub Release](https://img.shields.io/github/v/release/embetech-official/crc)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b8de2d81aca841dcb9f8c44d48c68b3e)](https://app.codacy.com/gh/embetech-official/crc/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)

## Overview

CRC is a small C library for calculating 8/16/32-bit checksums using standard, well-known polynomials. It provides simple, dependency-free functions and optional LUT-accelerated variants.

## Supported Polynomials

- CRC8-ITU (Poly 0x07, Init 0x00, no input/output bit reflection, XorOut 0x55)
- CRC16-CCITT BLUETOOTH CCITT-TRUE V-41-LSB KERMIT (Poly 0x1021, Init 0x0000, input/output bit reflection, XorOut 0x0000)
- CRC16-MODBUS (Poly 0x8005, Init 0xFFFF, input/output bit reflection, XorOut 0x0000)
- CRC32-POSIX/cksum (Poly 0x04C11DB7, Init 0x00000000, no input/output bit reflection, XorOut 0xFFFFFFFF)

## Core APIs

Headers:

- `embetech/crc8.h`
- `embetech/crc16.h`
- `embetech/crc32.h`

Version helper:

- `CRC_GetVersionString()` in `embetech/crc.h`

Representative functions:

- CRC-8 (ITU): `CRC8_ITU_Init`, `CRC8_ITU_UpdateUsingFormula`, `CRC8_ITU_UpdateUsingLut`, `CRC8_ITU_Finalize`
- CRC-16 CCITT: `CRC16_CCITT_Init`, `CRC16_CCITT_UpdateUsingFormula`, `CRC16_CCITT_UpdateUsingLut`, `CRC16_CCITT_Finalize`
- CRC-16 MODBUS: `CRC16_MODBUS_Init`, `CRC16_MODBUS_UpdateUsingFormula`, `CRC16_MODBUS_UpdateUsingLut`, `CRC16_MODBUS_Finalize`
- CRC-32 POSIX/cksum: `CRC32_CKSUM_Init`, `CRC32_CKSUM_UpdateUsingFormula`, `CRC32_CKSUM_UpdateUsingLut`, `CRC32_CKSUM_Finalize`

## Installation

This project uses CPM.cmake for source consumption and also supports installable CMake package metadata.

Using CPM.cmake in your project:

```cmake
# Download CPM.cmake (pin version as needed)
file(DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.42.0/CPM.cmake
  ${CMAKE_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=2020b4fc42dba44817983e06342e682ecfc3d2f484a581f11cc5731fbe4dce8a
)
include(${CMAKE_BINARY_DIR}/cmake/CPM.cmake)

# Add crc (pin to a released tag or major stream)
CPMAddPackage("gh:embetech-official/crc@2")

add_executable(app main.c)
target_link_libraries(app PRIVATE embetech::crc)
```

Include headers via:

```c
#include <embetech/crc.h>
#include <embetech/crc8.h>
#include <embetech/crc16.h>
#include <embetech/crc32.h>
```

## Build

Use CMake Presets (Ninja Multi-Config) for a streamlined workflow:

```sh
cmake --workflow --preset native-gcc
```

The workflow configures, builds Debug, runs tests, and installs Debug+Release.

## Options

- `CRC_TESTS` (default: ON if top-level): Builds unit tests (GoogleTest via CPM).
- `CRC_DOC` (default: ON if top-level): Builds Doxygen docs.
- `CRC_EXAMPLES` (default: ON if top-level): Builds example targets.
- `CRC_INSTALL` (default: ON): Enables install targets and generates CMake package config files.

Configure-time overrides, for example:

```sh
cmake --preset native-gcc -D CRC_TESTS=ON -D CRC_DOC=OFF -D CRC_EXAMPLES=ON
```

## Dependencies

- Runtime: none.
- Tests: `google/googletest` (fetched via CPM when tests are enabled).
- Optional: if `embetile` is available, an additional API file is compiled and linked automatically.

## Usage Example

Minimal example computing CRC-8, CRC-16 CCITT, and CRC-32 checksums:

```c
#include <embetech/crc8.h>
#include <embetech/crc16.h>
#include <embetech/crc32.h>

int main(void) {
  unsigned char data[100] = {0};

  // CRC-8 ITU (formula or LUT variant)
  uint8_t c8 = CRC8_ITU_Init();
  c8 = CRC8_ITU_UpdateUsingLut(data, sizeof(data), c8);
  c8 = CRC8_ITU_Finalize(c8);

  // CRC-16 CCITT
  uint16_t c16 = CRC16_CCITT_Init();
  c16 = CRC16_CCITT_UpdateUsingLut(data, sizeof(data), c16);
  c16 = CRC16_CCITT_Finalize(c16);

  // CRC-32 POSIX/cksum
  uint32_t c32 = CRC32_CKSUM_Init();
  c32 = CRC32_CKSUM_UpdateUsingLut(data, sizeof(data), c32);
  c32 = CRC32_CKSUM_Finalize(c32);

  (void)c8; (void)c16; (void)c32;
  return 0;
}
```

## Versioning

`CRC_GetVersionString()` returns the library version string. When built at the repository top-level, a short git commit id is appended (e.g., `X.Y.Z+abcdef12`).

## Contributing

Issues and PRs are welcome. Please use the provided presets to build, run tests, and keep changes focused.
