#ifndef _CHIP_8_CPU_EMULATOR_
#define _CHIP_8_CPU_EMULATOR_

#include "cpu_components.hpp"
#include "instructions.hpp"
#include "sdl_display.hpp"
#include <string>
#include <fstream>

class chip8_emulator
{
    private:
        chip8_cpu_components components;
        Instructions instructions;
        sdl_display display;
        uint8_t load_rom(std::string rom_path);
        void    load_fontset();

    public:
        chip8_emulator(std::string rom_path);
        void run();
};

#endif