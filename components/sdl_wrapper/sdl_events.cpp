#include "sdl_events.hpp"

sdl_event_handler::sdl_event_handler(std::array<SDL_Keycode, KEYPAD_SIZE>& keypad, SDL_Keycode quit_key)
{
    for(uint8_t i = 0; i < KEYPAD_SIZE; i++)
    {
        key_map[keypad[i]] = i;
    }
    escape_key = quit_key;
}

bool sdl_event_handler::handle_events(std::unique_ptr<uint8_t[]>& key_pad_chip8)
{
    bool quit = false;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            quit = true;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(key_map.find(event.key.keysym.sym) != key_map.end())
            {
                key_pad_chip8[key_map[event.key.keysym.sym]] = 1;
                std::cout << "Key pressed: " << key_map[event.key.keysym.sym] << std::endl;
            }
            else if(event.key.keysym.sym == escape_key)
            {
                quit = true;
                std::cout << "Escape key pressed" << std::endl;
            }
            else
            {
                // do nothing
            }
        }
        else if(event.type == SDL_KEYUP)
        {
            if(key_map.find(event.key.keysym.sym) != key_map.end())
            {
                key_pad_chip8[key_map[event.key.keysym.sym]] = 0;
            }
            else
            {
                // do nothing
            }
        }
    }
    return quit;
}