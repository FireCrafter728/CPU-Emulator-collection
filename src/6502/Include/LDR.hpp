#pragma once
#include <6502.hpp>

namespace _6502
{
    bool HandleLDR(CPU* cpu, const uint8_t Instruction, int32_t& Cycles);
}