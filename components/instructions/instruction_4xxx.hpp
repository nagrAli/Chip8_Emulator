#ifndef _INSTR_4XXX_HPP_
#define _INSTR_4XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_4xxx
{
    private:
        static void skip_next(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};
#endif