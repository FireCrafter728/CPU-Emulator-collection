#pragma once
#include <string>
#include <6502.hpp>

struct Args {
    std::string inputFile;
    std::string firmwareFile;
};

namespace utils
{
    std::string decimalToHex(int num);
    std::string decimalToBin(uint8_t num);
    void PrintRegs(_6502::CPU& cpu);
    uint16_t SPToAddr(uint8_t SP);
    Args parseArgs(int argc, char** argv);
    void PrintStackValue(_6502::CPU* cpu, uint8_t offset);
    void LoadMem(std::ifstream& Firmware, std::ifstream& Program, _6502::CPU* cpu);
    int8_t ConvertByteToSChar(uint8_t Byte);
    std::string GetColorCode(uint8_t ColorIndex);
}