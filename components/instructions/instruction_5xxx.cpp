#include "instruction_5xxx.hpp"

constexpr uint16_t VY_MASK      = 0x00F0u;
constexpr uint16_t VX_MASK      = 0x0F00u;
constexpr uint8_t  VX_SHIFT     = 8u;
constexpr uint8_t  VY_SHIFT     = 4u;

void instruction_5xxx::skip_instruction(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t vx_index = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t vy_index = (instruction & VY_MASK) >> VY_SHIFT;

    if(components->register_chip8.get_register_value(vx_index) == components->register_chip8.get_register_value(vy_index))
    {
        components->program_counter_chip8 += 2;
    }
    else
    {
        // do nothing
    }
}

void instruction_5xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    skip_instruction(components, instruction);
}