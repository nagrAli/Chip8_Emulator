#include "instruction_6xxx.hpp"

constexpr uint16_t DATA_MASK    = 0x00FFu;
constexpr uint16_t VX_MASK      = 0x0F00u;
constexpr uint8_t  VX_SHIFT     = 8u;

void instruction_6xxx::load_register(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t index = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t data  = (instruction & DATA_MASK);

    components->register_chip8.set_register_value(index, data);
}

void instruction_6xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    load_register(components, instruction);
}