#include "gtest/gtest.h"

#include <embetech/crc16.h>
#include <embetech/crc32.h>
#include <embetech/crc8.h>
#include <random>
#include <vector>

constexpr static uint64_t seed = 0x123456789ABCDEF0;

TEST(CRC, crc8check) {
  uint8_t data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  uint8_t crc1 = CRC8_Init();
  for(size_t i = 0; i < sizeof(data); ++i) {
    crc1 = CRC8_UpdateByte(data[i], crc1);
  }

  uint8_t crc2 = CRC8_UpdateBuf(data, sizeof(data), CRC8_Init());

  EXPECT_EQ(crc1, crc2) << "CRC8 mismatch when using byte-by-byte update vs buffer update";
}

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
      crc32 = CRC32_Append(buffer.data() + i, chunkSize, crc32);
      crc16Ccitt = CRC16_CCITT_UpdateBuf(buffer.data() + i, chunkSize, crc16Ccitt);
      crc16Modbus = CRC16_MODBUS_UpdateBuf(buffer.data() + i, chunkSize, crc16Modbus);
      crc8 = CRC8_UpdateBuf(buffer.data() + i, chunkSize, crc8);
    }
    crc32 = CRC32_Finalize(crc32);

    EXPECT_EQ(patternCrc32, crc32) << "CRC32 mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCrc16Ccitt, crc16Ccitt) << "CRC16_CCITT mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCrc16Modbus, crc16Modbus) << "CRC16_MODBUS mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCrc8, crc8) << "CRC8 mismatch for chunk size " << chunkSize;
  }
}
