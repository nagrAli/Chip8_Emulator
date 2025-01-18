#define SDL_MAIN_HANDLED 
#include <iostream>
#include "chip8_emulator.hpp"
int main()
{
    chip8_emulator emulator("../test_roms/test_opcode.ch8");
    emulator.run();
    return 0;
}

