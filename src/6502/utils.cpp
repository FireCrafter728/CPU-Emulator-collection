#include <utils.hpp>
#include <iostream>
#include <sstream>
#include <bitset>
#include <fstream>

std::string utils::decimalToHex(int num) {
    std::stringstream ss;
    ss << std::hex << num;
    return ss.str();
}

std::string utils::decimalToBin(uint8_t num) {
    std::bitset<8> bs(num);
    return bs.to_string();
}

void utils::PrintRegs(_6502::CPU& cpu)
{
    std::cout << "Regs: " << std::endl
    << "A: " << std::to_string(cpu.A) << ", 0x" << std::hex << decimalToHex(cpu.A) << std::endl
    << "X: " << std::to_string(cpu.X) << ", 0x" << std::hex << decimalToHex(cpu.X) << std::endl
    << "Y: " << std::to_string(cpu.Y) << ", 0x" << std::hex << decimalToHex(cpu.Y) << std::endl
    << "Carry Flag: " << std::to_string(cpu.C) << std::endl
    << "Zero Flag: " << std::to_string(cpu.Z) << std::endl
    << "Interrupt Disable: " << std::to_string(cpu.I) << std::endl
    << "Decimal Mode: " << std::to_string(cpu.D) << std::endl
    << "Break Command: " << std::to_string(cpu.B) << std::endl
    << "Overflow Flag: " << std::to_string(cpu.V) << std::endl
    << "Negative Flag: " << std::to_string(cpu.N) << std::endl
    << "Program Counter: 0x" << std::hex << decimalToHex(cpu.PC) << std::endl
    << "Stack Pointer: 0x" << std::hex << decimalToHex(cpu.SP) << std::endl
    << "Processor status: " << decimalToBin(cpu.PS) << std::endl;
}

uint16_t utils::SPToAddr(uint8_t SP)
{
    return 0x100 | SP;
}

Args utils::parseArgs(int argc, char** argv)
{
    Args args;
    for(int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if(arg == "-firmware") {
            args.firmwareFile = argv[++i];
            continue;
        }
        else args.inputFile = arg;
    }
    return args;
}

void utils::PrintStackValue(_6502::CPU* cpu, uint8_t offset)
{
    uint16_t AddrAbs = 0x100 | offset;
    int32_t stackValue = cpu->memory[AddrAbs];
    std::cout << "Stack value at offset: 0x" << std::hex << decimalToHex(offset) << ", address: 0x" << AddrAbs << ": " << std::hex << decimalToHex(stackValue) << "(" << stackValue << ")" << std::endl;
}

void utils::LoadMem(std::ifstream& Firmware, std::ifstream& Program, _6502::CPU* cpu)
{
    cpu->reset(Firmware);
    uint16_t Addr = 0x2000; 
    char Byte;
    while(Program.get(Byte) && Addr < 0xC000) cpu->memory[Addr++] = static_cast<uint8_t>(Byte);
}

int8_t utils::ConvertByteToSChar(uint8_t Byte)
{
    if(Byte > 127) return -(256 - Byte);
    else return Byte;
}

#include <string>

std::string utils::GetColorCode(uint8_t ColorIndex)
{
    switch (ColorIndex) {
        case 0: return "\033[30m";   // Black
        case 1: return "\033[31m";   // Red
        case 2: return "\033[32m";   // Green
        case 3: return "\033[33m";   // Yellow
        case 4: return "\033[34m";   // Blue
        case 5: return "\033[35m";   // Magenta
        case 6: return "\033[36m";   // Cyan
        case 7: return "\033[37m";   // White
        case 8: return "\033[90m";   // Bright Black (Gray)
        case 9: return "\033[91m";   // Bright Red
        case 10: return "\033[92m";  // Bright Green
        case 11: return "\033[93m";  // Bright Yellow
        case 12: return "\033[94m";  // Bright Blue
        case 13: return "\033[95m";  // Bright Magenta
        case 14: return "\033[96m";  // Bright Cyan
        case 15: return "\033[97m";  // Bright White
        default: return "\033[0m";   // Default (reset)
    }
}
