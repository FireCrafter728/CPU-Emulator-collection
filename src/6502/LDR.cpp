#include <LDR.hpp>

bool _6502::HandleLDR(CPU *cpu, const uint8_t Instruction, int32_t &Cycles)
{
    switch (Instruction)
    {
    case _6502::INS_LDA_IM:
    {
        cpu->LDSetStatus(cpu->A = cpu->Fetch(Cycles));
        break;
    }
    case _6502::INS_LDA_ZP:
    {
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles)));
        break;
    }
    case _6502::INS_LDA_ZPX:
    {
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
        Cycles--;
        break;
    }
    case _6502::INS_LDA_ABS:
    {
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles)));
        break;
    }
    case _6502::INS_LDA_ABSX:
    {
        uint16_t AbsAddr = cpu->Fetch16(Cycles);
        uint16_t AbsAddrX = AbsAddr + cpu->X;
        if (AbsAddrX - AbsAddr >= 0xFF)
            Cycles--; // If crosses page boundary, use another cycle
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrX));
        break;
    }
    case _6502::INS_LDA_ABSY:
    {
        uint16_t AbsAddr = cpu->Fetch16(Cycles);
        uint16_t AbsAddrY = AbsAddr + cpu->Y;
        if (AbsAddrY - AbsAddr >= 0xFF)
            Cycles--;
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY));
        break;
    }
    case _6502::INS_LDA_INX:
    {
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X)));
        Cycles--;
        break;
    }
    case _6502::INS_LDA_INY:
    {
        uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
        uint16_t EffAddrY = EffAddr + cpu->Y;
        if (EffAddrY - EffAddr >= 0xFF)
            Cycles--;
        cpu->LDSetStatus(cpu->A = cpu->ReadByteFrom16bAddr(Cycles, EffAddrY));
        break;
    }

        // LDX

    case _6502::INS_LDX_IM:
    {
        cpu->LDSetStatus(cpu->X = cpu->Fetch(Cycles));
        break;
    }
    case _6502::INS_LDX_ZP:
    {
        cpu->LDSetStatus(cpu->X = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles)));
        break;
    }
    case INS_LDX_ZPY:
    {
        cpu->LDSetStatus(cpu->X = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->Y));
        Cycles--;
        break;
    }
    case INS_LDX_ABS:
    {
        cpu->LDSetStatus(cpu->X = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles)));
        break;
    }
    case INS_LDX_ABSY:
    {
        uint16_t AbsAddr = cpu->Fetch16(Cycles);
        uint16_t AbsAddrY = AbsAddr + cpu->Y;
        if (AbsAddrY - AbsAddr >= 0xFF)
            Cycles--;
        cpu->LDSetStatus(cpu->X = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY));
        break;
    }

        // LDY

    case _6502::INS_LDY_IM:
    {
        cpu->Y = cpu->Fetch(Cycles);
        cpu->LDSetStatus(cpu->Y);
        break;
    }
    case _6502::INS_LDY_ZP:
    {
        cpu->Y = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
        cpu->LDSetStatus(cpu->Y);
        break;
    }
    case _6502::INS_LDY_ZPX:
    {
        cpu->Y = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X);
        Cycles--;
        cpu->LDSetStatus(cpu->Y);
        break;
    }
    case _6502::INS_LDY_ABS:
    {
        cpu->Y = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
        cpu->LDSetStatus(cpu->Y);
        break;
    }
    case _6502::INS_LDY_ABSX:
    {
        uint16_t AbsAddr = cpu->Fetch16(Cycles);
        uint16_t AbsAddrY = AbsAddr + cpu->X;
        cpu->Y = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY);
        if (AbsAddrY - AbsAddr >= 0xFF)
            Cycles--;
        cpu->LDSetStatus(cpu->Y);
        break;
    }
    default:
        return false;
    }

    return true;
}