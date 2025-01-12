#ifndef _CPU_COMPONENTS_HPP_
#define _CPU_COMPONENTS_HPP_
#include <iostream>
#include <cstdint>
#include "program_counter.hpp"
#include "index_register.hpp"
#include "memory_chip8.hpp"
#include "registers.hpp"
#include "stack_chip8.hpp"
#include "timer_chip8.hpp"
#include "cpu_display.hpp"
#include "cpu_keypad.hpp"

class chip8_cpu_components
{
    public:
        program_counter     program_counter_chip8;
        index_register      index_register_chip8;
        memory_chip_8       memory_chip8;
        registers           register_chip8;
        call_stack          stack_chip8;
        delay_timer         timer_chip8;
        cpu_display         display_chip8;
        cpu_keypad          keypad_chip8;
};
#endif