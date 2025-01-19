#ifndef _SDL_EVENTS_
#define _SDL_EVENTS_

#include <iostream>
#include <SDL2/SDL.h>
#include <map>
#include <array>
#include <memory>

constexpr uint8_t KEYPAD_SIZE = 16;
class sdl_event_handler
{
    private:
        SDL_Event event;
        std::map<SDL_Keycode, uint8_t> key_map;
        SDL_Keycode escape_key;
    public:
        sdl_event_handler(std::array<SDL_Keycode, KEYPAD_SIZE>& keypad, SDL_Keycode quit_key);
        bool handle_events(std::unique_ptr<uint8_t[]>& key_pad_chip8);
};

#endif