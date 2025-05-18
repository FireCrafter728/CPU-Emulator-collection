#include <STR.hpp>

bool _6502::HandleSTR(CPU* cpu, const uint8_t Instruction, int32_t& Cycles)
{
    switch(Instruction)
    {
        // STA

        case INS_STA_ZP:
        {
            cpu->memory.Write(cpu->A, cpu->Fetch(Cycles), Cycles);
            break;
        }
        case INS_STA_ZPX:
        {
            cpu->memory.Write(cpu->A, cpu->Fetch(Cycles) + cpu->X, Cycles);
            Cycles--;
            break;
        }
        case INS_STA_ABS:
        {
            cpu->memory.Write(cpu->A, cpu->Fetch16(Cycles), Cycles);
            break;
        }
        case INS_STA_ABSX:
        {
            cpu->memory.Write(cpu->A, cpu->Fetch16(Cycles) + cpu->X, Cycles);
            Cycles--;
            break;
        }
        case INS_STA_ABSY:
        {
            cpu->memory.Write(cpu->A, cpu->Fetch16(Cycles) + cpu->Y, Cycles);
            Cycles--;
            break;
        }
        case INS_STA_INX:
        {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X);
            Cycles--;
            cpu->memory.Write(cpu->A, EffAddr, Cycles);
            break;
        }
        case INS_STA_INY:
        {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t EffAddrY = EffAddr + cpu->Y;
            Cycles--;
            cpu->memory.Write(cpu->A, EffAddrY, Cycles);
            break;
        }

        // STX

        case INS_STX_ZP:
        {
            cpu->memory.Write(cpu->X, cpu->Fetch(Cycles), Cycles);
            break;
        }

        case INS_STX_ZPY:
        {
            cpu->memory.Write(cpu->X, cpu->Fetch(Cycles) + cpu->Y, Cycles);
            Cycles--;
            break;
        }

        case INS_STX_ABS:
        {
            cpu->memory.Write(cpu->X, cpu->Fetch16(Cycles), Cycles);
            break;
        }

        //STY

        case INS_STY_ZP:
        {
            cpu->memory.Write(cpu->Y, cpu->Fetch(Cycles), Cycles);
            break;
        }

        case INS_STY_ZPX:
        {
            cpu->memory.Write(cpu->Y, cpu->Fetch(Cycles) + cpu->X, Cycles);
            Cycles--;
            break;
        }

        case INS_STY_ABS:
        {
            cpu->memory.Write(cpu->Y, cpu->Fetch16(Cycles), Cycles);
            break;
        }

        default: return false;
    }

    return true;
}