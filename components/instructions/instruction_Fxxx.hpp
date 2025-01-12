#ifndef _INSTRUCTION_FXXX_HPP_
#define _INSTRUCTION_FXXX_HPP_

#include <iostream>
#include "cpu_components.hpp"

class instruction_fxxx
{
    private:
        static void fx07(chip8_cpu_components *components, uint16_t instruction);
        static void fx0A(chip8_cpu_components *components, uint16_t instruction);
        static void fx15(chip8_cpu_components *components, uint16_t instruction);
        static void fx18(chip8_cpu_components *components, uint16_t instruction);
        static void fx1E(chip8_cpu_components *components, uint16_t instruction);
        static void fx29(chip8_cpu_components *components, uint16_t instruction);
        static void fx33(chip8_cpu_components *components, uint16_t instruction);
        static void fx55(chip8_cpu_components *components, uint16_t instruction);
        static void fx65(chip8_cpu_components *components, uint16_t instruction);
        static void execute_instruction(chip8_cpu_components *components, uint16_t instruction);
    public:
        static void callback(chip8_cpu_components *components, uint16_t instruction);
};
#endif