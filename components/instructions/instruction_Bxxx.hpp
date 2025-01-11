#ifndef _INSTR_BXXX_HPP_
#define _INSTR_BXXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_Bxxx
{
    private:
        static void jump_to_nnn(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};
#endif