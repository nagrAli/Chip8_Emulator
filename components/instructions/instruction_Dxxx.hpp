#ifndef _INSTR_DXXX_HPP_
#define _INSTR_DXXX_HPP_

#include <iostream>
#include "cpu_components.hpp"


class instruction_Dxxx
{
    private:
        static void draw_sprite(chip8_cpu_components *components, uint16_t instruction);
    public: 
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};

#endif