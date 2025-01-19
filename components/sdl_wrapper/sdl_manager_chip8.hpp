#ifndef _SDL_MANAGER_CHIP8_
#define _SDL_MANAGER_CHIP8_

#include <iostream>
#include "sdl_display.hpp"
#include "sdl_events.hpp"

class sdl_manager_chip8 : public sdl_display, public sdl_event_handler
{
    public:
        sdl_manager_chip8(std::array<SDL_Keycode, KEYPAD_SIZE>& keypad, SDL_Keycode quit_key);
};
#endif