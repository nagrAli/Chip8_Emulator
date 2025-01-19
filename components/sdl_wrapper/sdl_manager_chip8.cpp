#include "sdl_manager_chip8.hpp"    

sdl_manager_chip8::sdl_manager_chip8(std::array<SDL_Keycode, KEYPAD_SIZE>& keypad, SDL_Keycode quit_key): sdl_display(), sdl_event_handler(keypad, quit_key)
{
    // Constructor
}