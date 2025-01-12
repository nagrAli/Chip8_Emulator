#include "instruction_Fxxx.hpp"

constexpr uint16_t  VX_MASK = 0x0F00;
constexpr uint16_t  MAX_KEYS = 16;
constexpr uint8_t   VX_SHIFT = 8;

void instruction_fxxx::fx07(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->register_chip8.set_register_value(x, components->timer_chip8);
}

void instruction_fxxx::fx0A(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    for(uint8_t i = 0; i < MAX_KEYS; i++)
    {
        if(components->keypad_chip8.get_key(i))
        {
            components->register_chip8.set_register_value(x, i);
            return;
        }
    }
    components->program_counter_chip8 -= 2;
}

void instruction_fxxx::fx15(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->timer_chip8 = components->register_chip8.get_register_value(x);
}
