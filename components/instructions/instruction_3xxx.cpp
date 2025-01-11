#include "instruction_3xxx.hpp"

void instruction_3xxx::perform_operation(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t data = instruction & DATA_MASK;
    uint8_t vx_index = (instruction & VX_MASK) >> 8;
    
    if(components->register_chip8.get_register_value(vx_index) == data)
    {
        components->program_counter_chip8 += 2;
    }
    else
    {
        // do nothing
    }
}

void instruction_3xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    perform_operation(components, instruction);
}