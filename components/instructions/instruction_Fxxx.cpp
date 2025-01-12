#include "instruction_Fxxx.hpp"

constexpr uint16_t  VX_MASK = 0x0F00;
constexpr uint16_t  SUB_INSTRUCTION_MASK = 0x00FF;
constexpr uint16_t  MAX_KEYS = 16;
constexpr uint8_t   VX_SHIFT = 8;
constexpr uint8_t   FONTSET_BYTE_SIZE = 5;

typedef enum
{
    FX07 = 0x0007,
    FX0A = 0x000A,
    FX15 = 0x0015,
    FX18 = 0x0018,
    FX1E = 0x001E,
    FX29 = 0x0029,
    FX33 = 0x0033,
    FX55 = 0x0055,
    FX65 = 0x0065
} fxxx_sub_instructions_t;

void instruction_Fxxx::fx07(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->register_chip8.set_register_value(x, components->timer_chip8);
}

void instruction_Fxxx::fx0A(chip8_cpu_components *components, uint16_t instruction)
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

void instruction_Fxxx::fx15(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->timer_chip8 = components->register_chip8.get_register_value(x);
}

void instruction_Fxxx::fx18(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->sound_timer_chip8 = components->register_chip8.get_register_value(x);
}

void instruction_Fxxx::fx1E(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->index_register_chip8 += components->register_chip8.get_register_value(x);
}

void instruction_Fxxx::fx29(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->index_register_chip8 = FONTSET_START_ADDRESS + (components->register_chip8.get_register_value(x) * FONTSET_BYTE_SIZE);
}

void instruction_Fxxx::fx33(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t value = components->register_chip8.get_register_value(x);
    components->memory_chip8.write_character(components->index_register_chip8, (value / 100));
    components->memory_chip8.write_character(components->index_register_chip8 + 1, ((value / 10) % 10));
    components->memory_chip8.write_character(components->index_register_chip8 + 2, (value % 10));
}

void instruction_Fxxx::fx55(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    for(uint8_t i = 0; i <= x; i++)
    {
        components->memory_chip8.write_instruction(components->index_register_chip8 + i, components->register_chip8.get_register_value(i));
    }
}

void instruction_Fxxx::fx65(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    for(uint8_t i = 0; i <= x; i++)
    {
        components->register_chip8.set_register_value(i, components->memory_chip8.read_instruction(components->index_register_chip8 + i));
    }
}

void instruction_Fxxx::execute_instruction(chip8_cpu_components *components, uint16_t instruction)
{
    fxxx_sub_instructions_t sub_instruction = static_cast<fxxx_sub_instructions_t>(instruction & SUB_INSTRUCTION_MASK);
    switch(sub_instruction)
    {
        case FX07:
            fx07(components, instruction);
            break;
        case FX0A:
            fx0A(components, instruction);
            break;
        case FX15:
            fx15(components, instruction);
            break;
        case FX18:
            fx18(components, instruction);
            break;
        case FX1E:
            fx1E(components, instruction);
            break;
        case FX29:
            fx29(components, instruction);
            break;
        case FX33:
            fx33(components, instruction);
            break;
        case FX55:
            fx55(components, instruction);
            break;
        case FX65:
            fx65(components, instruction);
            break;
        default:
            std::cerr << "Unknown instruction: " << instruction << std::endl;
            break;
    }
}

void instruction_Fxxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    execute_instruction(components, instruction);
}
