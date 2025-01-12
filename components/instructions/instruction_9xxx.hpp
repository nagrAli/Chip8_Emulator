#ifndef _INSTR_9XXX_HPP_
#define _INSTR_9XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_9xxx
{
    private:
        static void perform_operation(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif