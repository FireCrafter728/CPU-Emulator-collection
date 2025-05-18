#include <JIN.hpp>
#include <utils.hpp>
#include <stdexcept>

using namespace _6502;

bool _6502::HandleJIN(CPU* cpu, const uint8_t Instruction, int32_t& Cycles)
{
    switch(Instruction)
    {
        case INS_JSR:
        {
            cpu->Push16ToStack(cpu->PC + 2, Cycles); // Add 2 because we read 2 bytes in memory as the jump address
            cpu->PC = cpu->Fetch16(Cycles);
            Cycles--;
            break;
        }
        case INS_RTS:
        {
            if(cpu->SP >= 0xFF) return false; // END OF PROGRAM, return false to instantiate exit
            cpu->PC = cpu->Pop16FromStack(Cycles);
            Cycles -= 2;
            break;
        }
        case INS_JMP_ABS:
        {
            cpu->PC = cpu->Fetch16(Cycles);
            break;
        }
        case INS_JMP_IND:
        {
            cpu->PC = cpu->ReadWordFrom16bAddr(Cycles, cpu->Fetch16(Cycles));
            break;
        }
        case INS_BCC: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->C == 0) cpu->PC += Addr; 
            Cycles--;
            break;
        }
        case INS_BCS: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->C == 1) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_BEQ: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->Z == 1) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_BNE: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->Z == 0) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_BMI: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->N == 1) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_BPL: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->N == 0) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_BVC: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->V == 0) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_BVS: {
            int8_t Addr = utils::ConvertByteToSChar(cpu->Fetch(Cycles));
            if(cpu->V == 1) cpu->PC += Addr;
            Cycles--;
            break;
        }
        case INS_RTI: {
            cpu->PS = cpu->PopFromStack(Cycles);
            cpu->ClearFlags(cpu->PS_B);
            cpu->PC = cpu->Pop16FromStack(Cycles);
            break;
        }
        default: return false;
    }
    
    return true;
}