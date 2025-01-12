#ifndef _CHIP_8_CPU_EMULATOR_
#define _CHIP_8_CPU_EMULATOR_

#include "cpu_components.hpp"
#include "instructions.hpp"
#include "sdl_display.hpp"
class chip8_emulator
{
    private:
        chip8_cpu_components components;
        Instructions instructions;
        sdl_display display;
    public:
        void load_rom(const char *rom_path);
};

#endif