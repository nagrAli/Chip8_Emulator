#ifndef _REGISTERS_HPP_
#define _REGISTERS_HPP_

#include <iostream>
#include <cstdint>
#include <memory>

constexpr uint32_t NUMBER_OF_REGISTERS = 16;
constexpr uint8_t INVALID_VALUE = 0;
class registers
{
    private:
        std::unique_ptr<uint8_t[]> regs;
    public:
        registers();
        void set_register_value(uint8_t index, uint8_t value);
        uint8_t get_register_value(uint8_t index);
};
#endif