#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <cstdint>
#include <vector>

constexpr uint16_t MAX_STACK_LEVEL = 16;
constexpr uint16_t INVALID_PC = 0;
class call_stack
{
    private:
        std::vector<uint16_t> stack_holder;
        uint8_t stack_pointer;
    public:
        call_stack();
        void push_to_call_stack(uint16_t PC);
        uint16_t pop_from_call_stack();
        uint16_t get_stack_pointer();
};

#endif