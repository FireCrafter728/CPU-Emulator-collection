#include <6502.hpp>
#include <LDR.hpp>
#include <JIN.hpp>
#include <STR.hpp>
#include <StackOps.hpp>
#include <LogicalOps.hpp>
#include <RegOps.hpp>
#include <utils.hpp>
#include <fstream>

void _6502::Memory::Init()
{
    for (uint32_t i = 0; i < _6502::MAX_MEM; i++)
    {
        Data[i] = 0;
    }
}

uint8_t _6502::Memory::operator[](uint32_t Addr) const
{
    return Data[Addr];
}

uint8_t &_6502::Memory::operator[](uint32_t Addr)
{
    return Data[Addr];
}

void _6502::Memory::Write16(uint16_t Value, uint16_t Addr, int32_t &Cycles)
{
    Data[Addr] = Value & 0xFF;
    Data[Addr + 1] = (Value >> 8);
    Cycles -= 2;
}

void _6502::Memory::Write(uint8_t Value, uint16_t Addr, int32_t &Cycles)
{
    Data[Addr] = Value;
    Cycles--;
}

void _6502::CPU::PushToStack(uint8_t Value, int32_t& Cycles)
{
    memory.Write(Value, utils::SPToAddr(SP) - 1, Cycles);
    SP--;
    Cycles--;
}

void _6502::CPU::Push16ToStack(uint16_t Value, int32_t& Cycles)
{
    memory.Write16(Value, utils::SPToAddr(SP) - 1, Cycles);
    SP -= 2;
    Cycles--;
}

uint8_t _6502::CPU::PopFromStack(int32_t& Cycles)
{
    SP++;
    Cycles--;
    return ReadByteFrom16bAddr(Cycles, utils::SPToAddr(SP) - 1);
}

uint16_t _6502::CPU::Pop16FromStack(int32_t& Cycles)
{
    SP += 2;
    Cycles--;
    return ReadWordFrom16bAddr(Cycles, utils::SPToAddr(SP) - 1);
}

void _6502::CPU::reset(std::ifstream& Firmware)
{
    C = Z = I = D = B = V = N = 0;
    A = X = Y = 0;
    memory.Init();
    uint16_t Addr = 0xC000;
    char Byte;
    while(Firmware.get(Byte)) memory[Addr++] = static_cast<uint8_t>(Byte);
    PC = 0xC000; // The firmware sets up the reset vector during runtime, so we start at the firmware as the main entry
    SP = 0xFF;
}

// Fetch unit
uint8_t _6502::CPU::Fetch(int32_t &Cycles)
{
    uint8_t Data = memory[PC];
    PC++;
    Cycles--;
    return Data;
}

uint16_t _6502::CPU::Fetch16(int32_t &Cycles)
{
    uint16_t Data = memory[PC];
    PC++;

    Data |= (memory[PC] << 8);
    PC++;
    Cycles -= 2;
    return Data;
}

uint8_t _6502::CPU::ReadByteFrom8bAddr(int32_t &Cycles, uint8_t Addr)
{
    uint8_t Data = memory[Addr];
    Cycles--;
    return Data;
}

uint8_t _6502::CPU::ReadByteFrom16bAddr(int32_t &Cycles, uint16_t Addr)
{
    uint8_t Data = memory[Addr];
    Cycles--;
    return Data;
}

uint16_t _6502::CPU::ReadWordFrom8bAddr(int32_t &Cycles, uint8_t Addr)
{
    uint8_t l = ReadByteFrom8bAddr(Cycles, Addr);
    uint8_t h = ReadByteFrom8bAddr(Cycles, Addr + 1);
    return l | (h << 8);
}

uint16_t _6502::CPU::ReadWordFrom16bAddr(int32_t &Cycles, uint16_t Addr)
{
    uint8_t l = ReadByteFrom16bAddr(Cycles, Addr);
    uint8_t h = ReadByteFrom16bAddr(Cycles, Addr + 1);
    return l | (h << 8);
}

void _6502::CPU::LDSetStatus(uint8_t& Reg)
{
    ClearFlags(PS_Z | PS_N);
    Z = (Reg == 0);
    N = (Reg & 0b10000000) > 0;

    SetPS();
}

void _6502::CPU::SetTestStatus(uint8_t MemValue, uint8_t Final)
{
    ClearFlags(PS_Z | PS_N | PS_V);
    Z = (Final == 0);
    N = (MemValue & 0x80) != 0;
    V = (MemValue & 0x40) != 0;

    SetPS();
}

void _6502::CPU::SetADCStatus(uint16_t Res, uint8_t Value)
{
    ClearFlags(PS_C | PS_Z | PS_N | PS_V);
    C = (Res > 0xFF) ? 1 : 0;
    Z = (Res == 0) ? 1 : 0;
    N = (A & 0x80) ? 1 : 0;
    V = ((A ^ Value) & (A ^ Res) & 0x80) ? 1 : 0;
    SetPS();
}

void _6502::CPU::SetASLStatus(uint8_t bValue, uint8_t aValue)
{
    ClearFlags(PS_Z | PS_C | PS_N);
    Z = (aValue == 0) ? 1 : 0;
    C = (bValue & 0x80) ? 1 : 0;
    N = (aValue & 0x80) ? 1 : 0;
    SetPS();
}

void _6502::CPU::SetLSRStatus(uint8_t bValue, uint8_t aValue)
{
    ClearFlags(PS_Z | PS_C | PS_N);
    C = (bValue & 0x01) ? 1 : 0;
    Z = (aValue == 0) ? 1 : 0;
    N = 0;
    SetPS();
}

void _6502::CPU::SetROLStatus(uint8_t res)
{
    ClearFlags(PS_Z | PS_C | PS_N);
    C = (res & 0x01) ? 1 : 0;
    Z = (res == 0) ? 1 : 0;
    N = (res & 0x80) ? 1 : 0;
    SetPS();
}

void _6502::CPU::SetRORStatus(uint8_t res)
{
    ClearFlags(PS_Z | PS_C | PS_N);
    Z = (res == 0) ? 1 : 0;
    C = (res & 0x01) ? 1 : 0;
    N = (res & 0x80) ? 1 : 0;
    SetPS();
}

void _6502::CPU::SetCMPStatus(uint8_t res, uint8_t m)
{
    ClearFlags(PS_C | PS_Z | PS_N);
    C = (res >= m) ? 1 : 0;
    Z = (res == 0) ? 1 : 0;
    N = (res & 0b10000000) > 0;
    SetPS();
}

void _6502::CPU::SetSBCStatus(uint8_t bValue, uint8_t aValue)
{
    uint16_t res = aValue - bValue - (1 - C);
    ClearFlags(PS_Z | PS_C | PS_N | PS_V);
    if (res <= 0xFF) {
        C = 1;
    } else {
        C = 0;
    }
    if ((res & 0xFF) == 0) {
        Z = 1;
    }
    if (res & 0x80) {
        N = 1;
    }
    if (((aValue ^ bValue) & 0x80) && ((aValue ^ (res & 0xFF)) & 0x80)) {
        V = 1;
    }

    SetPS();
}


void _6502::CPU::SetPS()
{
    PS = (C << 7) | (Z << 6) | (I << 5) | (D << 4) | (B << 3) | (V << 2) | (N << 1) | 0x01;
}

void _6502::CPU::ClearFlags(uint8_t Flags)
{
    if (Flags & PS_C) C = 0;   
    if (Flags & PS_Z) Z = 0;   
    if (Flags & PS_I) I = 0;   
    if (Flags & PS_D) D = 0;   
    if (Flags & PS_B) B = 0;   
    if (Flags & PS_V) V = 0;   
    if (Flags & PS_N) N = 0; 
    SetPS();
}

void _6502::CPU::Run() {
    int32_t CyclesUsed = 0;
    do {
        CyclesUsed = Execute(1); // As long as we have 1 cycle, the instruction will be executed
    } while(CyclesUsed > 1);
} 

int32_t _6502::CPU::Execute(int32_t Cycles)
{
    const int32_t StartCycles = Cycles;
    while (Cycles > 0)
    {
        uint8_t Instruction;
        Instruction = Fetch(Cycles);
        if(_6502::HandleLDR(this, Instruction, Cycles)) continue;
        if(_6502::HandleJIN(this, Instruction, Cycles)) continue;
        if(_6502::HandleSTR(this, Instruction, Cycles)) continue;
        if(_6502::HandleSTO(this, Instruction, Cycles)) continue;
        if(_6502::HandleLOG(this, Instruction, Cycles)) continue;
        if(_6502::HandleREG(this, Instruction, Cycles)) continue;
        return 0;
    }

    return StartCycles - Cycles;
}