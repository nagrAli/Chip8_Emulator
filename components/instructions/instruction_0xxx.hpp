#ifndef _INSTR_0XXX_HPP_
#define _INSTR_0XXX_HPP_

#include <iostream>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_0xxx
{
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
    private:
        static void return_from_subroutine(chip8_cpu_components *components);
        static void clear_screen(chip8_cpu_components *components);

};
#endif