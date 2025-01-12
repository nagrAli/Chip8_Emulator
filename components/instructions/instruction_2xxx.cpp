#include "instruction_2xxx.hpp"

constexpr uint16_t ADDRESS_MASK = 0x0FFFu;

void instruction_2xxx::call_sub_routine(chip8_cpu_components *components, uint16_t instruction)
{
    uint16_t address = instruction & ADDRESS_MASK;
    components->stack_chip8.push_to_call_stack(components->program_counter_chip8);
    components->program_counter_chip8 = address;
}

void instruction_2xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    call_sub_routine(components, instruction);
}