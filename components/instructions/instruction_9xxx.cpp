#include "instruction_9xxx.hpp"

void instruction_9xxx::perform_operation(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t index_reg_x = (instruction & INDEX_MASK_VX) >> SHIFT_REG_X; 
    uint8_t index_reg_y = (instruction & INDEX_MASK_VY) >> SHIFT_REG_Y;
    uint8_t vy = components->register_chip8.get_register_value(index_reg_y);
    uint8_t vx = components->register_chip8.get_register_value(index_reg_x);

    if(vx != vy)
    {
        components->program_counter_chip8 += 2;
    }
    else
    {
        // do nothing
    }
}

void instruction_9xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    perform_operation(components, instruction);
}