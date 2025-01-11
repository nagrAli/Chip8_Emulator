#ifndef _INSTR_BXXX_HPP_
#define _INSTR_BXXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_Cxxx
{
    private:
        static void set_register_to_nn(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};
#endif