#ifndef _PROGRAM_COUNTER_H_
#define _PROGRAM_COUNTER_H_

#include <cstdint>
class program_counter
{
    private:
        uint16_t PC;
    public:
        program_counter& operator=(uint16_t val);
        program_counter& operator+=(uint16_t val);
        program_counter& operator-=(uint16_t val);
        operator uint16_t() const;
};
#endif