#include "instruction_7xxx.hpp"

void instruction_7xxx::load_and_add_register(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t index = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t data  = (instruction & DATA_MASK);
    uint8_t reg_val = components->register_chip8.get_register_value(index);

    components->register_chip8.set_register_value(index, (reg_val + data));
}

void instruction_7xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    load_and_add_register(components, instruction);
}