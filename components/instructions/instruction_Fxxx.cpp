#include "instruction_Fxxx.hpp"

constexpr uint16_t VX_MASK = 0x0F00;
constexpr uint8_t VX_SHIFT = 8;

void instruction_fxxx::fx07(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t x = (instruction & VX_MASK) >> VX_SHIFT;
    components->register_chip8.set_register_value(x, components->timer_chip8);
}