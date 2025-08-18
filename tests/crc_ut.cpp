#include "gtest/gtest.h"

#include <embetech/crc16.h>
#include <embetech/crc32.h>
#include <embetech/crc8.h>
#include <format>
#include <random>
#include <vector>

TEST(CRC, PatternCheckWithMixedBufferSize) {
  constexpr static uint32_t dataSize = 128 * 1024;

  std::vector<std::uint8_t> buffer;
  constexpr static uint64_t seed = 0x123456789ABCDEF0;
  std::mt19937 rng(seed);
  std::uniform_int_distribution<std::uint8_t> dist(0, 255);
  for(size_t i = 0; i < dataSize; ++i) {
    buffer.push_back(dist(rng));
  }

  // generated using both concurrently: https://www.crccalc.com/ and https://devbeaver.com/checksum-calculator-validator-tools/crc
  uint32_t patternCrc32 = 0x9096DFE3;
  uint16_t patternModbus = 0x9E2B;
  uint16_t patternCcittTrue = 0x7E4A;
  uint8_t patternCrc8Itu = 0xEC;

  for(size_t chunkSize = 1; chunkSize < dataSize; chunkSize *= 2) {
    uint32_t crc32FormulaIc = CRC32_CKSUM_Init();
    uint32_t crc32Lut = CRC32_CKSUM_Init();
    uint16_t crc16ModbusLut = CRC16_MODBUS_Init();
    uint16_t crc16ModbusFormulaIc = CRC16_MODBUS_Init();
    uint16_t crc16CcittLut = CRC16_CCITT_Init();
    uint16_t crc16CcittFormulaIc = CRC16_CCITT_Init();
    uint8_t crc8ItuFormulaIc = CRC8_ITU_Init();
    uint8_t crc8ItuLut = CRC8_ITU_Init();

    for(size_t i = 0; i < dataSize; i += chunkSize) {
      crc32FormulaIc = CRC32_CKSUM_UpdateFormulaIc(buffer.data() + i, chunkSize, crc32FormulaIc);
      crc32Lut = CRC32_CKSUM_UpdateLut(buffer.data() + i, chunkSize, crc32Lut);
      crc16ModbusLut = CRC16_MODBUS_UpdateLut(buffer.data() + i, chunkSize, crc16ModbusLut);
      crc16ModbusFormulaIc = CRC16_MODBUS_UpdateFormulaIc(buffer.data() + i, chunkSize, crc16ModbusFormulaIc);
      crc16CcittLut = CRC16_CCITT_UpdateLut(buffer.data() + i, chunkSize, crc16CcittLut);
      crc16CcittFormulaIc = CRC16_CCITT_UpdateFormulaIc(buffer.data() + i, chunkSize, crc16CcittFormulaIc);
      crc8ItuFormulaIc = CRC8_ITU_UpdateFormulaIc(buffer.data() + i, chunkSize, crc8ItuFormulaIc);
      crc8ItuLut = CRC8_ITU_UpdateLut(buffer.data() + i, chunkSize, crc8ItuLut);
    }
    crc32FormulaIc = CRC32_CKSUM_Finalize(crc32FormulaIc);
    crc32Lut = CRC32_CKSUM_Finalize(crc32Lut);
    crc16ModbusLut = CRC16_MODBUS_Finalize(crc16ModbusLut);
    crc16ModbusFormulaIc = CRC16_MODBUS_Finalize(crc16ModbusFormulaIc);
    crc16CcittLut = CRC16_CCITT_Finalize(crc16CcittLut);
    crc16CcittFormulaIc = CRC16_CCITT_Finalize(crc16CcittFormulaIc);
    crc8ItuFormulaIc = CRC8_ITU_Finalize(crc8ItuFormulaIc);
    crc8ItuLut = CRC8_ITU_Finalize(crc8ItuLut);

    EXPECT_EQ(patternCrc32, crc32FormulaIc) << "CRC32 mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCrc32, crc32Lut) << "CRC32 mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternModbus, crc16ModbusLut) << "CRC16_MODBUS mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternModbus, crc16ModbusFormulaIc) << "CRC16_MODBUS mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCcittTrue, crc16CcittLut) << "CRC16_CCITT mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCcittTrue, crc16CcittFormulaIc) << "CRC16_CCITT mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCrc8Itu, crc8ItuFormulaIc) << "CRC8_ITU mismatch for chunk size " << chunkSize;
    EXPECT_EQ(patternCrc8Itu, crc8ItuLut) << "CRC8_ITU mismatch for chunk size " << chunkSize;
  }
}
