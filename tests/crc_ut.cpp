#include "gtest/gtest.h"

#include <embetech/crc16.h>
#include <embetech/crc32.h>
#include <embetech/crc8.h>
#include <random>
#include <vector>

constexpr static uint64_t seed = 0x123456789ABCDEF0;

TEST(CRC, MixedBuffers) {
  constexpr static uint32_t dataSize = 1024 * 1024 * 16;

  std::vector<std::uint8_t> buffer;
  std::mt19937 rng(seed);
  std::uniform_int_distribution<std::uint8_t> dist(0, 255);
  for(size_t i = 0; i < dataSize; ++i) {
    buffer.push_back(dist(rng));
  }

  uint32_t patternCrc32 = CRC32_Init();
  patternCrc32 = CRC32_UpdateBuf(buffer.data(), dataSize, patternCrc32);
  patternCrc32 = CRC32_Finalize(patternCrc32);

  uint16_t patternCrc16Ccitt = CRC16_CCITT_Init();
  patternCrc16Ccitt = CRC16_CCITT_UpdateBuf(buffer.data(), dataSize, patternCrc16Ccitt);

  uint16_t patternCrc16Modbus = CRC16_MODBUS_Init();
  patternCrc16Modbus = CRC16_MODBUS_UpdateBuf(buffer.data(), dataSize, patternCrc16Modbus);

  uint8_t patternCrc8 = CRC8_Init();
  patternCrc8 = CRC8_UpdateBuf(buffer.data(), dataSize, patternCrc8);

  for(size_t chunkSize = 1; chunkSize < dataSize; chunkSize *= 2) {
    uint32_t crc32 = CRC32_Init();
    uint16_t crc16Ccitt = CRC16_CCITT_Init();
    uint16_t crc16Modbus = CRC16_MODBUS_Init();
    uint8_t crc8 = CRC8_Init();

    for(size_t i = 0; i < dataSize; i += chunkSize) {
      crc32 = CRC32_UpdateBuf(buffer.data() + i, chunkSize, crc32);
      crc16Ccitt = CRC16_CCITT_UpdateBuf(buffer.data() + i, chunkSize, crc16Ccitt);
      crc16Modbus = CRC16_MODBUS_UpdateBuf(buffer.data() + i, chunkSize, crc16Modbus);
      crc8 = CRC8_UpdateBuf(buffer.data() + i, chunkSize, crc8);
    }
    crc32 = CRC32_Finalize(32);

    EXPECT_EQ(patternCrc32, crc32);
    EXPECT_EQ(patternCrc16Ccitt, crc16Ccitt);
    EXPECT_EQ(patternCrc16Modbus, crc16Modbus);
    EXPECT_EQ(patternCrc8, crc8);
  }
}
