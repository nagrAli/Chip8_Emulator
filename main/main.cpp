#define SDL_MAIN_HANDLED 
#include <iostream>
#include "chip8_emulator.hpp"
#include "sdl_events.hpp"
#include <memory>
#include "input_keys.hpp"
#include <array> 
#include <SDL2/SDL.h>   

std::array<SDL_Keycode, 16> CHIP8_KEYMAP = {
    SDLK_x, SDLK_1, SDLK_2, SDLK_3, // 0x0 - 0x3
    SDLK_q, SDLK_w, SDLK_e, SDLK_a, // 0x4 - 0x7
    SDLK_s, SDLK_d, SDLK_z, SDLK_c, // 0x8 - 0xB
    SDLK_4, SDLK_r, SDLK_f, SDLK_v  // 0xC - 0xF
};
int main()
{
    chip8_emulator emulator("../test_roms/test_opcode.ch8", CHIP8_KEYMAP, SDLK_ESCAPE);
    emulator.run();
    // std::unique_ptr<uint8_t[]> key_map(new uint8_t[TOTAL_KEYS]);
    // std::array<uint8_t, TOTAL_KEYS> keypad = {SDLK_1, SDLK_2, SDLK_3, SDLK_4, SDLK_q, SDLK_w, SDLK_e, SDLK_r, SDLK_a, SDLK_s, SDLK_d, SDLK_f, SDLK_z, SDLK_x, SDLK_c, SDLK_v};
    // SDL_Keycode quit_key = SDLK_ESCAPE;
    // sdl_event_handler sdl_events(keypad, quit_key);
    // bool quit = false;
    // while(quit == false)
    // {
    //     quit = sdl_events.handle_events(key_map);
    // }
    

    return 0;
}

