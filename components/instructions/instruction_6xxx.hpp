#ifndef _INSTR_6XXX_HPP_
#define _INSTR_6XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_6xxx
{
    private:
        static void load_register(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif