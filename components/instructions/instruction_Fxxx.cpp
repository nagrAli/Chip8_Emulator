#include "instruction_Fxxx.hpp"

constexpr uint16_t  VX_MASK = 0x0F00;
constexpr uint16_t  MAX_KEYS = 16;
constexpr uint8_t   VX_SHIFT = 8;
constexpr uint8_t   FONTSET_BYTE_SIZE = 5;

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

void instruction_fxxx::fx18(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->sound_timer_chip8 = components->register_chip8.get_register_value(x);
}

void instruction_fxxx::fx1E(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->index_register_chip8 += components->register_chip8.get_register_value(x);
}

void instruction_fxxx::fx29(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->index_register_chip8 = FONTSET_START_ADDRESS + (components->register_chip8.get_register_value(x) * FONTSET_BYTE_SIZE);
}

void instruction_fxxx::fx33(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t value = components->register_chip8.get_register_value(x);
    components->memory_chip8.write_character(components->index_register_chip8, (value / 100));
    components->memory_chip8.write_character(components->index_register_chip8 + 1, ((value / 10) % 10));
    components->memory_chip8.write_character(components->index_register_chip8 + 2, (value % 10));
}

void instruction_fxxx::fx55(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    for(uint8_t i = 0; i <= x; i++)
    {
        components->memory_chip8.write_instruction(components->index_register_chip8 + i, components->register_chip8.get_register_value(i));
    }
}

void instruction_fxxx::fx65(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    for(uint8_t i = 0; i <= x; i++)
    {
        components->register_chip8.set_register_value(i, components->memory_chip8.read_instruction(components->index_register_chip8 + i));
    }
}
