#include "registers.hpp"

registers::registers() : regs(std::make_unique<uint8_t[]>(NUMBER_OF_REGISTERS))
{
    std::cout<<"Register Constructor Called\n";
}

void registers::set_register_value(uint8_t index, uint8_t value)
{
    if(index < NUMBER_OF_REGISTERS)
        regs[index] = value;
}

uint8_t registers::get_register_value(uint8_t index)
{
    if(index < NUMBER_OF_REGISTERS)
        return regs[index];
    else
        return INVALID_VALUE;
}