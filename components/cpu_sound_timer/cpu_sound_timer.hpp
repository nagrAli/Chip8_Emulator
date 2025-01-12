#ifndef _CPU_SOUND_TIMER_HPP_
#define _CPU_SOUND_TIMER_HPP_

#include <iostream>

class cpu_sound_timer
{
    private:
        uint8_t sound_timer = 0;
    public:
        cpu_sound_timer& operator=(uint8_t val);
        operator uint8_t() const;
};
#endif