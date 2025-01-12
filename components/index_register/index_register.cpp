#include "index_register.hpp"

index_register& index_register::operator=(uint16_t val)
{
    reg = val;
    return *this;
}

index_register& index_register::operator+=(uint16_t val)
{
    reg += val;
    return *this;
}

index_register& index_register::operator-=(uint16_t val)
{
    reg -= val;
    return *this;
}

index_register:: operator uint16_t()const
{
    return reg;
}
