#ifndef _INSTR_EXXX_HPP_
#define _INSTR_EXXX_HPP_

#include <iostream>
#include "cpu_components.hpp"

class instruction_exxx
{
    private:
        static void exnn(chip8_cpu_components *components, uint16_t instruction);
    public: 
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};
#endif 