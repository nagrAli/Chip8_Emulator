#include "stack_chip8.hpp"

call_stack::call_stack()
{
    stack_pointer = 0;
    stack_holder.reserve(MAX_STACK_LEVEL);
}

void call_stack::push_to_call_stack(uint16_t PC)
{
    if(stack_holder.size() < MAX_STACK_LEVEL)
    {
        stack_holder.insert(stack_holder.begin() + stack_pointer, PC);
        stack_pointer ++;
    }
    else
    {
        // do nothing
    }
}

uint16_t call_stack::pop_from_call_stack()
{
    if(!stack_holder.empty())
    {
        return INVALID_PC;
    }
    else
    {
        uint16_t val = stack_holder[stack_pointer];
        stack_holder.erase(stack_holder.begin() + stack_pointer);
        stack_pointer --;
        return val;
    }
}

uint16_t call_stack::get_stack_pointer()
{
    return stack_pointer;
}
