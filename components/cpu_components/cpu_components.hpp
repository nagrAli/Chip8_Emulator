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
#include "cpu_sound_timer.hpp"

constexpr uint8_t FONTSET_SIZE = 80;
constexpr uint16_t FONTSET_START_ADDRESS = 0x50;
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
        cpu_sound_timer     sound_timer_chip8;
        uint8_t fontset[FONTSET_SIZE] =
        {
            0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
            0x20, 0x60, 0x20, 0x20, 0x70, // 1
            0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
            0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
            0x90, 0x90, 0xF0, 0x10, 0x10, // 4
            0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
            0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
            0xF0, 0x10, 0x20, 0x40, 0x40, // 7
            0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
            0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
            0xF0, 0x90, 0xF0, 0x90, 0x90, // A
            0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
            0xF0, 0x80, 0x80, 0x80, 0xF0, // C
            0xE0, 0x90, 0x90, 0x90, 0xE0, // D
            0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
            0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };
};
#endif