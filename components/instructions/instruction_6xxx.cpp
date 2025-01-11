#include "instruction_6xxx.hpp"

void instruction_6xxx::load_register(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t index = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t data  = (instruction & DATA_MASK);

    components->register_chip8.set_register_value(index, data);
}

void instruction_6xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    load_register(components, instruction);
}