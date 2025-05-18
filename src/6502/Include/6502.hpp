#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <iomanip>

namespace _6502
{    
    enum {
        INS_LDA_IM    = 0xA9,
        INS_LDA_ZP    = 0xA5,
        INS_LDA_ZPX   = 0xB5,
        INS_LDA_ABS   = 0xAD,
        INS_LDA_ABSX  = 0xBD,
        INS_LDA_ABSY  = 0xB9,
        INS_LDA_INX   = 0xA1,
        INS_LDA_INY   = 0xB1,
    
        INS_LDX_IM    = 0xA2,
        INS_LDX_ZP    = 0xA6,
        INS_LDX_ZPY   = 0xB6,
        INS_LDX_ABS   = 0xAE,
        INS_LDX_ABSY  = 0xBE,
    
        INS_LDY_IM    = 0xA0,
        INS_LDY_ZP    = 0xA4,
        INS_LDY_ZPX   = 0xB4,
        INS_LDY_ABS   = 0xAC,
        INS_LDY_ABSX  = 0xBC,
    
        INS_STA_ZP    = 0x85,
        INS_STA_ZPX   = 0x95,
        INS_STA_ABS   = 0x8D,
        INS_STA_ABSX  = 0x9D,
        INS_STA_ABSY  = 0x99,
        INS_STA_INX   = 0x81,
        INS_STA_INY   = 0x91,
    
        INS_STX_ZP    = 0x86,
        INS_STX_ZPY   = 0x96,
        INS_STX_ABS   = 0x8E,
    
        INS_STY_ZP    = 0x84,
        INS_STY_ZPX   = 0x94,
        INS_STY_ABS   = 0x8C,
    
        INS_JSR       = 0x20,
        INS_RTS       = 0x60,
        INS_JMP_ABS   = 0x4C,
        INS_JMP_IND   = 0x6C,

        INS_TSX         = 0xBA,
        INS_TXS         = 0x9A,
        INS_PHA         = 0x48,
        INS_PHP         = 0x08,
        INS_PLA         = 0x68,
        INS_PLP         = 0x28,

        INS_AND_IM      = 0x29,
        INS_AND_ZP      = 0x25,
        INS_AND_ZPX     = 0x35,
        INS_AND_ABS     = 0x2D,
        INS_AND_ABSX    = 0x3D,
        INS_AND_ABSY    = 0x39,
        INS_AND_INX     = 0x21,
        INS_AND_INY     = 0x31,

        INS_EOR_IM      = 0x49,
        INS_EOR_ZP      = 0x45,
        INS_EOR_ZPX     = 0x55,
        INS_EOR_ABS     = 0x4D,
        INS_EOR_ABSX    = 0x5D,
        INS_EOR_ABSY    = 0x59,
        INS_EOR_INX     = 0x41,
        INS_EOR_INY     = 0x51,

        INS_ORA_IM      = 0x09,
        INS_ORA_ZP      = 0x05,
        INS_ORA_ZPX     = 0x15,
        INS_ORA_ABS     = 0x0D,
        INS_ORA_ABSX    = 0x1D,
        INS_ORA_ABSY    = 0x19,
        INS_ORA_INX     = 0x01,
        INS_ORA_INY     = 0x11,

        INS_BIT_ZP      = 0x24,
        INS_BIT_ABS     = 0x2C,

        INS_TAX         = 0xAA,
        INS_TXA         = 0x8A,
        INS_TAY         = 0xA8,
        INS_TYA         = 0x98,

        INS_INC_ZP      = 0xE6,
        INS_INC_ZPX     = 0xF6,
        INS_INC_ABS     = 0xEE,
        INS_INC_ABSX    = 0xFE,

        INS_INX         = 0xE8,
        INS_INY         = 0xC8,

        INS_DEC_ZP      = 0xC6,
        INS_DEC_ZPX     = 0xD6,
        INS_DEC_ABS     = 0xCE,
        INS_DEC_ABSX    = 0xDE,

        INS_DEX         = 0xCA,
        INS_DEY         = 0x88,

        INS_BEQ         = 0xF0,
        INS_BCC         = 0x90,
        INS_BCS         = 0xB0,
        INS_BMI         = 0x30,
        INS_BNE         = 0xD0,
        INS_BPL         = 0x10,
        INS_BVC         = 0x50,
        INS_BVS         = 0x70,

        INS_CLC         = 0x18,
        INS_SEC         = 0x38,

        INS_ADC_IM      = 0x69,
        INS_ADC_ZP      = 0x65,
        INS_ADC_ZPX     = 0x75,
        INS_ADC_ABS     = 0x6D,
        INS_ADC_ABSX    = 0x7D,
        INS_ADC_ABSY    = 0x79,
        INS_ADC_INX     = 0x61,
        INS_ADC_INY     = 0x71,

        INS_ASL_ACM     = 0x0A,
        INS_ASL_ZP      = 0x06,
        INS_ASL_ZPX     = 0x16,
        INS_ASL_ABS     = 0x0E,
        INS_ASL_ABSX    = 0x1E,

        INS_LSR_ACM     = 0x4A,
        INS_LSR_ZP      = 0x46,
        INS_LSR_ZPX     = 0x56,
        INS_LSR_ABS     = 0x4E,
        INS_LSR_ABSX    = 0x5E,

        INS_ROL_ACM     = 0x2A,
        INS_ROL_ZP      = 0x26,
        INS_ROL_ZPX     = 0x36,
        INS_ROL_ABS     = 0x2E,
        INS_ROL_ABSX    = 0x3E,

        INS_ROR_ACM     = 0x6A,
        INS_ROR_ZP      = 0x66,
        INS_ROR_ZPX     = 0x76,
        INS_ROR_ABS     = 0x6E,
        INS_ROR_ABSX    = 0x7E,

        INS_BRK         = 0x00,

        INS_CLD         = 0xD8,
        INS_CLI         = 0x58,
        INS_CLV         = 0xB8,

        INS_CMP_IM      = 0xC9,
        INS_CMP_ZP      = 0xC5,
        INS_CMP_ZPX     = 0xD5,
        INS_CMP_ABS     = 0xCD,
        INS_CMP_ABSX    = 0xDD,
        INS_CMP_ABSY    = 0xD9,
        INS_CMP_INX     = 0xC1,
        INS_CMP_INY     = 0xD1,

        INS_CPX_IM      = 0xE0,
        INS_CPX_ZP      = 0xE4,
        INS_CPX_ABS     = 0xEC,

        INS_CPY_IM      = 0xC0,
        INS_CPY_ZP      = 0xC4,
        INS_CPY_ABS     = 0xCC,

        INS_NOP         = 0xEA,

        INS_RTI         = 0x40,

        INS_SBC_IM      = 0xE9,
        INS_SBC_ZP      = 0xE5,
        INS_SBC_ZPX     = 0xF5,
        INS_SBC_ABS     = 0xED,
        INS_SBC_ABSX    = 0xFD,
        INS_SBC_ABSY    = 0xF9,
        INS_SBC_INX     = 0xE1,
        INS_SBC_INY     = 0xF1,

        // Interrupt mappings

        INT_PRINT       = 0xF4,
    };

    struct Memory;
    struct CPU;

    const uint32_t MAX_MEM = 1024 * 64;
}

struct _6502::Memory
{
    uint8_t Data[_6502::MAX_MEM];
    void Init();
    uint8_t operator[](uint32_t Addr) const;
    uint8_t &operator[](uint32_t Addr);
    void Write16(uint16_t Value, uint16_t Addr, int32_t &Cycles);
    void Write(uint8_t Value, uint16_t Addr, int32_t &Cycles);
};

struct _6502::CPU
{
    uint16_t PC; // program counter
    uint8_t SP; // stack pointer

    uint8_t A, X, Y; // regs

    uint8_t PS;

    uint8_t C : 1; // Carry flag
    uint8_t Z : 1; // Zero flag
    uint8_t I : 1; // Interrupt disable
    uint8_t D : 1; // Decimal mode
    uint8_t B : 1; // Break command
    uint8_t V : 1; // Overflow flag
    uint8_t N : 1; // Negative flag

    enum {
        PS_C,
        PS_Z,
        PS_I,
        PS_D,
        PS_B,
        PS_V,
        PS_N,
    };

    Memory memory;

    void Run();
    void reset(std::ifstream& Firmware);
    uint8_t Fetch(int32_t &Cycles);
    uint16_t Fetch16(int32_t &Cycles);
    uint8_t ReadByteFrom8bAddr(int32_t &Cycles, uint8_t Addr);
    uint8_t ReadByteFrom16bAddr(int32_t &Cycles, uint16_t Addr);
    uint16_t ReadWordFrom8bAddr(int32_t &Cycles, uint8_t Addr);
    uint16_t ReadWordFrom16bAddr(int32_t &Cycles, uint16_t Addr);
    void LDSetStatus(uint8_t& Reg);
    int32_t Execute(int32_t Cycles);
    void PushToStack(uint8_t Value, int32_t& Cycles);
    void Push16ToStack(uint16_t Value, int32_t& Cycles);
    uint8_t PopFromStack(int32_t& Cycles);
    uint16_t Pop16FromStack(int32_t& Cycles);
    void SetTestStatus(uint8_t MemValue, uint8_t Final);
    void SetADCStatus(uint16_t Res, uint8_t Value);
    void SetASLStatus(uint8_t bValue, uint8_t aValue);
    void SetLSRStatus(uint8_t bValue, uint8_t aValue);
    void SetROLStatus(uint8_t res);
    void SetRORStatus(uint8_t res);
    void SetCMPStatus(uint8_t res, uint8_t m);
    void SetSBCStatus(uint8_t bValue, uint8_t aValue);
    void SetPS();
    void ClearFlags(uint8_t Flags);
};