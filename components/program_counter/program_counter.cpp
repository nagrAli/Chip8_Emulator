#include "program_counter.hpp"

program_counter& program_counter::operator=(uint16_t val)
{
    PC = val;
    return *this;
}

program_counter& program_counter::operator+=(uint16_t val)
{
    PC += val;
    return *this;
}

program_counter& program_counter::operator-=(uint16_t val)
{
    PC -= val;
    return *this;
}

program_counter::operator uint16_t() const
{
    return PC;
}