#ifndef _SDL_DISPLAY_
#define _SDL_DISPLAY_

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

constexpr uint16_t SDL_SCREEN_WIDTH = 64;   
constexpr uint16_t SDL_SCREEN_HEIGHT = 32;
constexpr uint16_t SDL_PIXEL_SIZE = 10;
constexpr char TAG[] = "Chip8 Emulator";
class sdl_display
{
    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
    public:
        sdl_display();
        void clear_screen();
        void update_screen(const std::unique_ptr<uint8_t[]>& screen);
        ~sdl_display();
};
#endif