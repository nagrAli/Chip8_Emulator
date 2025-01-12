#ifndef _INSTR_CXXX_HPP_
#define _INSTR_CXXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>
#include <random>

class instruction_Cxxx
{
    private:
        static void set_register_to_nn(chip8_cpu_components *components, uint16_t instruction);
        static uint8_t random_number();
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};
#endif