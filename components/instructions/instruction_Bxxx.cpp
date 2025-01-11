#include "instruction_Bxxx.hpp"

constexpr uint16_t ADDRESS_MASK = 0x0FFF;
constexpr uint8_t INDEX_0 = 0;
void instruction_Bxxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    jump_to_nnn(components, instruction);
}

void instruction_Bxxx::jump_to_nnn(chip8_cpu_components *components, uint16_t instruction)
{
    uint16_t address = instruction & ADDRESS_MASK;
    components->program_counter_chip8 = (address + components->register_chip8.get_register_value(INDEX_0));
}