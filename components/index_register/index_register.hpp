#ifndef _INDEX_REGISTER_H_
#define _INDEX_REGISTER_H_

#include <cstdint>

class index_register
{
    private:
        uint16_t reg;
    public:
        index_register& operator=(uint16_t val);
        operator uint16_t() const;
};
#endif