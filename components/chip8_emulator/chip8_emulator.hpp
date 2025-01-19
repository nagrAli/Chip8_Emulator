#ifndef _CHIP_8_CPU_EMULATOR_
#define _CHIP_8_CPU_EMULATOR_

#include "cpu_components.hpp"
#include "instructions.hpp"
#include "sdl_display.hpp"
#include <string>
#include <fstream>
#include "sdl_manager_chip8.hpp"

class chip8_emulator
{
    private:
        uint32_t rom_size_emu = 0;
        chip8_cpu_components components;
        Instructions instructions;
        sdl_manager_chip8 sdl_manager;
        uint8_t load_rom(std::string rom_path);
        void    load_fontset();

    public:
        chip8_emulator(std::string rom_path, std::array<SDL_Keycode, KEYPAD_SIZE>& keypad, SDL_Keycode quit_key);
        void run();
};

#endif