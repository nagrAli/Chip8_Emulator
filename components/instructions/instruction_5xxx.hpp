#ifndef _INSTR_5XXX_HPP_
#define _INSTR_5XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_5xxx
{
    private:
        static void skip_instruction(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif
