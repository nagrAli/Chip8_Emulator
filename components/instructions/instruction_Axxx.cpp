#include "instruction_Axxx.hpp"

constexpr uint16_t ADDRESS_MASK  = 0x0FFF;

void instruction_Axxx::load_index_register(chip8_cpu_components *components, uint16_t instruction)
{
    uint16_t address = instruction & ADDRESS_MASK;
    components->index_register_chip8 = address;
}

void instruction_Axxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    load_index_register(components, instruction);
}