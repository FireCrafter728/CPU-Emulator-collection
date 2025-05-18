#pragma once
#include <6502.hpp>

namespace _6502
{
    bool HandleSTO(CPU* cpu, const uint8_t Instruction, int32_t& Cycles);
}