#include <StackOps.hpp>

bool _6502::HandleSTO(CPU* cpu, const uint8_t Instruction, int32_t& Cycles) {
    switch(Instruction) {
        case _6502::INS_TSX: {
            cpu->X = cpu->SP;
            Cycles--;
            cpu->LDSetStatus(cpu->X);
            break;
        }
        case _6502::INS_TXS: {
            cpu->SP = cpu->X;
            Cycles--;
            break;
        }
        case _6502::INS_PHA: {
            cpu->PushToStack(cpu->A, Cycles);
            break;
        }
        case _6502::INS_PHP: {
            cpu->PushToStack(cpu->PS, Cycles);
            break;
        }
        case _6502::INS_PLA: {
            cpu->A = cpu->PopFromStack(Cycles);
            Cycles--;
            break;
        }
        case _6502::INS_PLP: {
            cpu->PS = cpu->PopFromStack(Cycles);
            Cycles--;
            break;
        }
        default: return false;
    }
    return true;
}