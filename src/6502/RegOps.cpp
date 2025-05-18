#include <RegOps.hpp>
#include <utils.hpp>

bool _6502::HandleREG(CPU* cpu, const uint8_t Instruction, int32_t& Cycles)
{
    switch(Instruction) {
        case _6502::INS_TAX: {
            cpu->LDSetStatus(cpu->X = cpu->A);
            Cycles--;
            break;
        }
        case _6502::INS_TXA: {
            cpu->LDSetStatus(cpu->A = cpu->X);
            Cycles--;
            break;
        }
        case _6502::INS_TAY: {
            cpu->LDSetStatus(cpu->Y = cpu->A);
            Cycles--;
            break;
        }
        case _6502::INS_TYA: {
            cpu->LDSetStatus(cpu->A = cpu->Y);
            Cycles--;
            break;
        }
        case _6502::INS_INC_ZP: {
            uint8_t Addr = cpu->Fetch(Cycles);
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr) + 1;
            cpu->memory.Write(Value, static_cast<uint16_t>(Addr), Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_INC_ZPX: {
            uint8_t Addr = cpu->Fetch(Cycles) + cpu->X;
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr) + 1;
            Cycles--;
            cpu->memory.Write(Value, static_cast<uint16_t>(Addr), Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_INC_ABS: {
            uint16_t Addr = cpu->Fetch16(Cycles);
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr) + 1;
            cpu->memory.Write(Value, Addr, Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_INC_ABSX: {
            uint16_t Addr = cpu->Fetch16(Cycles) + cpu->X;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr) + 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_INX: {
            cpu->X++;
            Cycles--;
            cpu->LDSetStatus(cpu->X);
            break;
        }
        case _6502::INS_INY: {
            cpu->Y++;
            Cycles--;
            cpu->LDSetStatus(cpu->Y);
            break;
        }
        case _6502::INS_DEC_ZP: {
            uint8_t Addr = cpu->Fetch(Cycles);
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr) - 1;
            cpu->memory.Write(Value, static_cast<uint16_t>(Addr), Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_DEC_ZPX: {
            uint8_t Addr = cpu->Fetch(Cycles) + cpu->X;
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr) - 1;
            Cycles--;
            cpu->memory.Write(Value, static_cast<uint16_t>(Addr), Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_DEC_ABS: {
            uint16_t Addr = cpu->Fetch16(Cycles);
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr) - 1;
            cpu->memory.Write(Value, Addr, Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_DEC_ABSX: {
            uint16_t Addr = cpu->Fetch16(Cycles) + cpu->X;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr) - 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            Cycles--;
            cpu->LDSetStatus(Value);
            break;
        }
        case _6502::INS_DEX: {
            cpu->X--;
            Cycles--;
            cpu->LDSetStatus(cpu->X);
            break;
        }
        case _6502::INS_DEY: {
            cpu->Y--;
            Cycles--;
            cpu->LDSetStatus(cpu->Y);
            break;
        }
        case _6502::INS_CLC: {
            cpu->C = 0;
            Cycles--;
            break;
        }
        case _6502::INS_SEC: {
            cpu->C = 1;
            Cycles--;
            break;
        }
        case _6502::INS_ADC_IM: {
            uint8_t Value = cpu->Fetch(Cycles);
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_ZP: {
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_ZPX: {
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X);
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_ABS: {
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_ABSX: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrX = AbsAddr + cpu->X;
            if(AbsAddrX - AbsAddr >= 0xFF) Cycles--;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrX);
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_ABSY: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrY = AbsAddr + cpu->Y;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY);
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_INX: {
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_ADC_INY: {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t EffAddrY = EffAddr + cpu->Y;
            if(EffAddrY - EffAddr >= 0xFF) Cycles--;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, EffAddrY);
            uint16_t Res = cpu->A + Value + cpu->C;
            cpu->SetADCStatus(Res, Value);
            break;
        }
        case _6502::INS_BRK: {
            uint16_t SavedPC = cpu->PC + 1;
            cpu->Push16ToStack(SavedPC, Cycles);
            uint8_t PS = (cpu->C << 7) | (cpu->Z << 6) | (cpu->I << 5) | (cpu->D << 4) | 1 | (cpu->V << 2) | (cpu->N << 1) | 0x01;
            cpu->PushToStack(PS, Cycles);
            uint16_t IV = cpu->ReadWordFrom16bAddr(Cycles, 0xFFFE);
            cpu->PC = IV;
            break;
        }
        case _6502::INS_CLD: {
            cpu->D = 0;
            Cycles--;
            break;
        }
        case _6502::INS_CLI: {
            cpu->I = 0;
            Cycles--;
            break;
        }
        case _6502::INS_CLV: {
            cpu->V = 0;
            Cycles--;
            break;
        }
        case _6502::INS_SBC_IM: {
            uint8_t Value = cpu->Fetch(Cycles);
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_ZP: {
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_ZPX: {
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X);
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_ABS: {
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_ABSX: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrX = AbsAddr + cpu->X;
            if(AbsAddrX - AbsAddr >= 0xFF) Cycles--;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrX);
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_ABSY: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrY = AbsAddr + cpu->Y;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY);
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_INX: {
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->A = Res & 0xFF;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        case _6502::INS_SBC_INY: {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t EffAddrY = EffAddr + cpu->Y;
            if(EffAddrY - EffAddr >= 0xFF) Cycles--;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, EffAddrY);
            uint16_t Res = cpu->A - Value - cpu->C;
            cpu->SetSBCStatus(Res, Value);
            break;
        }
        default: return false;
    }

    return true;
}