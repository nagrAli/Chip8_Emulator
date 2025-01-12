#ifndef _INSTR_2XXX_HPP_
#define _INSTR_2XXX_HPP_

#include <iostream>
#include <stdlib.h>
#include <cpu_components.hpp>

class instruction_2xxx
{
    private:
        static void call_sub_routine(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);

};
#endif