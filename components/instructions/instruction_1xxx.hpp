#ifndef _INSTR_1XXX_HPP_
#define _INSTR_1XXX_HPP_

#include <iostream>
#include <cstdint>
#include <cpu_components.hpp>

class instruction_1xxx
{
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
    private:
        static void jump_to_address(chip8_cpu_components *components, uint16_t instruction);

};

#endif