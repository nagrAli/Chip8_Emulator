#ifndef _INSTR_0XXX_HPP_
#define _INSTR_0XXX_HPP_

#include <iostream>
#include <cstdint>
#include <cpu_components.hpp>

constexpr uint16_t INSTR_CLS = 0x00E0;
constexpr uint16_t INSTR_RET = 0x00EE;


class instruction_0xxx
{
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
    private:
        static void return_from_subroutine(chip8_cpu_components *components);

};
#endif