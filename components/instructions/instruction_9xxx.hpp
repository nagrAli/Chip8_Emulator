#ifndef _INSTR_9XXX_HPP_
#define _INSTR_9XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

constexpr uint16_t INDEX_MASK_VX   = 0x0F00;
constexpr uint16_t INDEX_MASK_VY   = 0x00F0;
constexpr uint8_t  SHIFT_REG_X     = 8u;
constexpr uint8_t  SHIFT_REG_Y     = 4u;

class instruction_9xxx
{
    private:
        static void perform_operation(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif