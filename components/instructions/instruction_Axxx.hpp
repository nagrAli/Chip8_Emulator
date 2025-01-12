#ifndef _INSTR_AXXX_HPP_
#define _INSTR_AXXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_Axxx
{
    private:
        static void load_index_register(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif