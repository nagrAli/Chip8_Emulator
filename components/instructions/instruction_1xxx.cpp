#include "instruction_1xxx.hpp"

constexpr uint16_t ADDRESS_MASK = 0x0FFFu;

void instruction_1xxx::jump_to_address(chip8_cpu_components *components, uint16_t instruction)
{
    uint16_t address = instruction & ADDRESS_MASK;
    components->program_counter_chip8 = address;
}

void instruction_1xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    jump_to_address(components, instruction);
}