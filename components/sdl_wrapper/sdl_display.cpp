#include "sdl_display.hpp"

sdl_display::sdl_display() : window(nullptr, SDL_DestroyWindow), renderer(nullptr, SDL_DestroyRenderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window.reset(SDL_CreateWindow(TAG, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SDL_SCREEN_WIDTH * SDL_PIXEL_SIZE, SDL_SCREEN_HEIGHT * SDL_PIXEL_SIZE, SDL_WINDOW_SHOWN));
    if (window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    if (renderer == nullptr)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
}

sdl_display::~sdl_display()
{
    SDL_Quit();
}

void sdl_display::update_screen(const std::unique_ptr<uint8_t[]>& screen)
{
    for (int y = 0; y < SDL_SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SDL_SCREEN_WIDTH; x++)
        {
            bool is_pixel_set = (screen[y*SDL_SCREEN_WIDTH + x] == 1);
            if (is_pixel_set)
            {
                SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
            }
            SDL_Rect rect = {x * SDL_PIXEL_SIZE, y * SDL_PIXEL_SIZE, SDL_PIXEL_SIZE, SDL_PIXEL_SIZE};
            SDL_RenderFillRect(renderer.get(), &rect);
        }
    }
    SDL_RenderPresent(renderer.get());
}

void sdl_display::clear_screen()
{
    SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(renderer.get());
}