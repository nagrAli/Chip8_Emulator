#include "timer_chip8.hpp"

delay_timer& delay_timer::operator=(uint8_t val)
{
    delay_counter = val;
    return *this;
}

delay_timer::operator uint8_t() const
{
    return delay_counter;
}