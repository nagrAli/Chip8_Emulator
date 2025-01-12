#include "cpu_sound_timer.hpp"

cpu_sound_timer& cpu_sound_timer::operator=(uint8_t val)
{
    sound_timer = val;
    return *this;
}

cpu_sound_timer::operator uint8_t() const
{
    return sound_timer;
}