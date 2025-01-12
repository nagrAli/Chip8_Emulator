#include "instruction_Exxx.hpp"


constexpr uint16_t INSTRUCTION_MASK = 0x0F00;
constexpr uint16_t BYTE_MASK = 0x00FF;
constexpr uint8_t  INSTRUCTION_SHIFT = 8u;
constexpr uint8_t  INSTR_0x9E = 0x9E;
constexpr uint8_t  INSTR_0xA1 = 0xA1;
void instruction_Exxx::exnn(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t register_x = (instruction & INSTRUCTION_MASK) >> INSTRUCTION_SHIFT;
    uint8_t instruction_byte = instruction & BYTE_MASK;

    if (instruction_byte == INSTR_0x9E)
    {
        if (components->keypad_chip8.get_key(components->register_chip8.get_register_value(register_x)))
        {
            components->program_counter_chip8 += 2;
        }
        else
        {
            // do nothing
        }
    }
    else if (instruction_byte == INSTR_0xA1)
    {
        if (!components->keypad_chip8.get_key(components->register_chip8.get_register_value(register_x)))
        {
            components->program_counter_chip8 += 2;
        }
        else
        {
            // do nothing
        }
    }
    else
    {
        // do nothing
    }
}

void instruction_Exxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    exnn(components, instruction);
}