#include <LogicalOps.hpp>

bool _6502::HandleLOG(CPU* cpu, const uint8_t Instruction, int32_t& Cycles)
{
    switch(Instruction) {
        case _6502::INS_AND_IM: {
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->Fetch(Cycles));
            break;
        }
        case _6502::INS_AND_ZP: {
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles)));
            break;
        }
        case _6502::INS_AND_ZPX: {
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
            Cycles--;
            break;
        }
        case _6502::INS_AND_ABS: {
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles)));
            break;
        }
        case _6502::INS_AND_ABSX: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrX = AbsAddr + cpu->X;
            if(AbsAddrX - AbsAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom16bAddr(Cycles, AbsAddrX));
            break;
        }
        case _6502::INS_AND_ABSY: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrY = AbsAddr + cpu->Y;
            if(AbsAddrY - AbsAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY));
            break;
        }
        case _6502::INS_AND_INX: {
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X)));
            Cycles--;
            break;
        }
        case _6502::INS_AND_INY: {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t EffAddrY = EffAddr + cpu->Y;
            if(EffAddrY - EffAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A & cpu->ReadByteFrom16bAddr(Cycles, EffAddrY));
            break;
        }
        case _6502::INS_EOR_IM: {
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->Fetch(Cycles));
            break;
        }
        case _6502::INS_EOR_ZP: {
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles)));
            break;
        }
        case _6502::INS_EOR_ZPX: {
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
            Cycles--;
            break;
        }
        case _6502::INS_EOR_ABS: {
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles)));
            break;
        }
        case _6502::INS_EOR_ABSX: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrX = AbsAddr + cpu->X;
            if(AbsAddrX - AbsAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom16bAddr(Cycles, AbsAddrX));
            break;
        }
        case _6502::INS_EOR_ABSY: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrY = AbsAddr + cpu->Y;
            if(AbsAddrY - AbsAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY));
            break;
        }
        case _6502::INS_EOR_INX: {
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X)));
            Cycles--;
            break;
        }
        case _6502::INS_EOR_INY: {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t EffAddrY = EffAddr + cpu->Y;
            if(EffAddrY - EffAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A ^ cpu->ReadByteFrom16bAddr(Cycles, EffAddrY));
            break;
        }
        case _6502::INS_ORA_IM: {
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->Fetch(Cycles));
            break;
        }
        case _6502::INS_ORA_ZP: {
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles)));
            break;
        }
        case _6502::INS_ORA_ZPX: {
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
            Cycles--;
            break;
        }
        case _6502::INS_ORA_ABS: {
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles)));
            break;
        }
        case _6502::INS_ORA_ABSX: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrX = AbsAddr + cpu->X;
            if(AbsAddrX - AbsAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom16bAddr(Cycles, AbsAddrX));
            break;
        }
        case _6502::INS_ORA_ABSY: {
            uint16_t AbsAddr = cpu->Fetch16(Cycles);
            uint16_t AbsAddrY = AbsAddr + cpu->Y;
            if(AbsAddrY - AbsAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom16bAddr(Cycles, AbsAddrY));
            break;
        }
        case _6502::INS_ORA_INX: {
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X)));
            Cycles--;
            break;
        }
        case _6502::INS_ORA_INY: {
            uint16_t EffAddr = cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            uint16_t EffAddrY = EffAddr + cpu->Y;
            if(EffAddrY - EffAddr >= 0xFF) Cycles--;
            cpu->LDSetStatus(cpu->A = cpu->A | cpu->ReadByteFrom16bAddr(Cycles, EffAddrY));
            break;
        }
        case _6502::INS_BIT_ZP: {
            uint8_t MemValue = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            cpu->SetTestStatus(MemValue, cpu->A & MemValue);
            break;
        }
        case _6502::INS_BIT_ABS: {
            uint8_t MemValue = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            cpu->SetTestStatus(MemValue, cpu->A & MemValue);
            break;
        }
        case _6502::INS_ASL_ACM: {
            uint8_t Old = cpu->A;
            cpu->A <<= 1;
            Cycles--;
            cpu->SetASLStatus(Old, cpu->A);
            break;
        }
        case _6502::INS_ASL_ZP: {
            uint8_t Addr = cpu->Fetch(Cycles);
            uint8_t OldValue = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            uint8_t Value = OldValue << 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetASLStatus(OldValue, Value);
            break;
        }
        case _6502::INS_ASL_ZPX: {
            uint8_t Addr = cpu->Fetch(Cycles) + cpu->X;
            Cycles--;
            uint8_t OldValue = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            uint8_t Value = OldValue << 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetASLStatus(OldValue, Value);
            break;
        }
        case _6502::INS_ASL_ABS: {
            uint16_t Addr = cpu->Fetch16(Cycles);
            uint8_t OldValue = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            uint8_t Value = OldValue << 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetASLStatus(OldValue, Value);
            break;
        }
        case _6502::INS_ASL_ABSX: {
            uint16_t Addr = cpu->Fetch16(Cycles) + cpu->X;
            Cycles--;
            uint8_t OldValue = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            uint8_t Value = OldValue << 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetASLStatus(OldValue, Value);
            break;
        }
        case _6502::INS_LSR_ACM: {
            uint8_t Old = cpu->A;
            cpu->A >>= 1;
            Cycles--;
            cpu->SetLSRStatus(Old, cpu->A);
            break;
        }
        case _6502::INS_LSR_ZP: {
            uint8_t Addr = cpu->Fetch(Cycles);
            uint8_t OldValue = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            uint8_t Value = OldValue >> 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetLSRStatus(OldValue, Value);
            break;
        }
        case _6502::INS_LSR_ZPX: {
            uint8_t Addr = cpu->Fetch(Cycles) + cpu->X;
            Cycles--;
            uint8_t OldValue = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            uint8_t Value = OldValue >> 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetLSRStatus(OldValue, Value);
            break;
        }
        case _6502::INS_LSR_ABS: {
            uint16_t Addr = cpu->Fetch16(Cycles);
            uint8_t OldValue = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            uint8_t Value = OldValue >> 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetLSRStatus(OldValue, Value);
            break;
        }
        case _6502::INS_LSR_ABSX: {
            uint16_t Addr = cpu->Fetch16(Cycles) + cpu->X;
            Cycles--;
            uint8_t OldValue = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            uint8_t Value = OldValue >> 1;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetLSRStatus(OldValue, Value);
            break;
        }
        case _6502::INS_ROL_ACM: {
            uint8_t OldCarry = cpu->C;
            cpu->C = (cpu->A & 0x80) ? 1 : 0;
            cpu->A = (cpu->A << 1) | OldCarry;
            Cycles--;
            cpu->SetROLStatus(cpu->A);
            break;
        }
        case _6502::INS_ROL_ZP: {
            uint8_t OldCarry = cpu->C;
            uint8_t Addr = cpu->Fetch(Cycles);
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            cpu->C = (Value & 0x80) ? 1 : 0;
            Value = (Value << 1) | OldCarry;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetROLStatus(Value);
            break;
        }
        case _6502::INS_ROL_ZPX: {
            uint8_t OldCarry = cpu->C;
            uint8_t Addr = cpu->Fetch(Cycles) + cpu->X;
            Cycles--;
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            cpu->C = (Value & 0x80) ? 1 : 0;
            Value = (Value << 1) | OldCarry;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetROLStatus(Value);
            break;
        }
        case _6502::INS_ROL_ABS: {
            uint8_t OldCarry = cpu->C;
            uint16_t Addr = cpu->Fetch16(Cycles);
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            cpu->C = (Value & 0x80) ? 1 : 0;
            Value = (Value << 1) | OldCarry;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetROLStatus(Value);
            break;
        }
        case _6502::INS_ROL_ABSX: {
            uint8_t OldCarry = cpu->C;
            uint16_t Addr = cpu->Fetch16(Cycles) + cpu->X;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            cpu->C = (Value & 0x80) ? 1 : 0;
            Value = (Value << 1) | OldCarry;
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetROLStatus(Value);
            break;
        }
        case _6502::INS_ROR_ACM: {
            uint8_t OldCarry = cpu->C;
            cpu->C = (cpu->A & 0x01) ? 1 : 0;
            cpu->A = (cpu->A >> 1) | (OldCarry << 7);
            Cycles--;
            cpu->SetRORStatus(cpu->A);
            break;
        }
        case _6502::INS_ROR_ZP: {
            uint8_t OldCarry = cpu->C;
            uint8_t Addr = cpu->Fetch(Cycles);
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            cpu->C = (Value & 0x01) ? 1 : 0;
            Value = (Value >> 1) | (OldCarry << 7);
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetRORStatus(Value);
            break;
        }
        case _6502::INS_ROR_ZPX: {
            uint8_t OldCarry = cpu->C;
            uint8_t Addr = cpu->Fetch(Cycles) + cpu->X;
            Cycles--;
            uint8_t Value = cpu->ReadByteFrom8bAddr(Cycles, Addr);
            cpu->C = (Value & 0x01) ? 1 : 0;
            Value = (Value >> 1) | (OldCarry << 7);
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetRORStatus(Value);
            break;
        }
        case _6502::INS_ROR_ABS: {
            uint8_t OldCarry = cpu->C;
            uint16_t Addr = cpu->Fetch16(Cycles);
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            cpu->C = (Value & 0x01) ? 1 : 0;
            Value = (Value >> 1) | (OldCarry << 7);
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetRORStatus(Value);
            break;
        }
        case _6502::INS_ROR_ABSX: {
            uint8_t OldCarry = cpu->C;
            uint16_t Addr = cpu->Fetch16(Cycles) + cpu->X;
            uint8_t Value = cpu->ReadByteFrom16bAddr(Cycles, Addr);
            cpu->C = (Value & 0x01) ? 1 : 0;
            Value = (Value >> 1) | (OldCarry << 7);
            Cycles--;
            cpu->memory.Write(Value, Addr, Cycles);
            cpu->SetRORStatus(Value);
            break;
        }
        case _6502::INS_CMP_IM: {
            uint8_t m = cpu->Fetch(Cycles);
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_ZP: {
            uint8_t m = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_ZPX: {
            uint8_t m = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X);
            Cycles--;
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_ABS: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_ABSX: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles) + cpu->X);
            Cycles--;
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_ABSY: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles) + cpu->Y);
            Cycles--;
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_INX: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles) + cpu->X));
            Cycles--;
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CMP_INY: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->ReadWordFrom8bAddr(Cycles, cpu->Fetch(Cycles)) + cpu->Y);
            cpu->SetCMPStatus(cpu->A - m, m);
            break;
        }
        case _6502::INS_CPX_IM: {
            uint8_t m = cpu->Fetch(Cycles);
            cpu->SetCMPStatus(cpu->X - m, m);
            break;
        }
        case _6502::INS_CPX_ZP: {
            uint8_t m = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            cpu->SetCMPStatus(cpu->X - m, m);
            break;
        }
        case _6502::INS_CPX_ABS: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            cpu->SetCMPStatus(cpu->X - m, m);
            break;
        }
        case _6502::INS_CPY_IM: {
            uint8_t m = cpu->Fetch(Cycles);
            cpu->SetCMPStatus(cpu->Y - m, m);
            break;
        }
        case _6502::INS_CPY_ZP: {
            uint8_t m = cpu->ReadByteFrom8bAddr(Cycles, cpu->Fetch(Cycles));
            cpu->SetCMPStatus(cpu->Y - m, m);
            break;
        }
        case _6502::INS_CPY_ABS: {
            uint8_t m = cpu->ReadByteFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            cpu->SetCMPStatus(cpu->Y - m, m);
            break;
        }
        case _6502::INS_NOP: {
            Cycles--;
            break;
        }
        default: return false;
    }

    return true;
}