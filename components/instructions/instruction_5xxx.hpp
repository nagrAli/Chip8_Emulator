#ifndef _INSTR_5XXX_HPP_
#define _INSTR_5XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

constexpr uint16_t VY_MASK      = 0x00FFu;
constexpr uint16_t VX_MASK      = 0x0F00u;
constexpr uint8_t  VX_SHIFT     = 8u;
constexpr uint8_t  VY_SHIFT     = 4u;

class instruction_5xxx
{
    private:
        static void skip_instruction(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif
