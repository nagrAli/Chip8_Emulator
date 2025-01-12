#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <cstdint>
class delay_timer
{
    private:
        uint8_t delay_counter = 0;
    public:
        delay_timer& operator=(uint8_t val);
        operator uint8_t() const;
};
#endif