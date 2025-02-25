#include "instruction_Cxxx.hpp"

uint16_t const REGISTER_X_MASK = 0x0F00;
uint16_t const VALUE_MASK = 0x00FF;
uint8_t const REGISTER_X_SHIFT = 8u;


void instruction_Cxxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    set_register_to_nn(components, instruction);
}

uint8_t instruction_Cxxx::random_number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 255); 
    return static_cast<uint8_t>(dist(gen));
}

void instruction_Cxxx::set_register_to_nn(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t register_index = (instruction & REGISTER_X_MASK) >> REGISTER_X_SHIFT;
    uint8_t value = instruction & VALUE_MASK;
    components->register_chip8.set_register_value(register_index, (random_number() & value));
}