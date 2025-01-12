#include "instruction_4xxx.hpp"

constexpr uint16_t DATA_MASK    = 0x00FFu;
constexpr uint16_t VX_MASK      = 0x0F00u;

void instruction_4xxx::skip_next(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t data = instruction & DATA_MASK;
    uint8_t vx_index = (instruction & VX_MASK) >> 8;
    
    if(components->register_chip8.get_register_value(vx_index) != data)
    {
        components->program_counter_chip8 += 2;
    }
    else
    {
        // do nothing
    }
}

void instruction_4xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    skip_next(components, instruction);
}