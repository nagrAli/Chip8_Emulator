#include "cpu_display.hpp"

constexpr uint8_t MASK = 0x80;

cpu_display::cpu_display()
{
    display = std::make_unique<uint8_t[]>(CPU_SCREEN_WIDTH * CPU_SCREEN_HEIGHT);
    clear_display();
}

void cpu_display::clear_display()
{
    for (int i = 0; i < CPU_SCREEN_WIDTH * CPU_SCREEN_HEIGHT; i++)
    {
        display[i] = 0;
    }
}

void cpu_display::invert_pixel(uint8_t x, uint8_t y)
{
    display[x + y * CPU_SCREEN_WIDTH] ^= 1;
}

void cpu_display::set_pixel(uint8_t x, uint8_t y, uint8_t value)
{
    display[x + y * CPU_SCREEN_WIDTH] = value;
}

uint8_t cpu_display::get_pixel(uint8_t x, uint8_t y)
{
    return display[x + y * CPU_SCREEN_WIDTH];
}

void cpu_display::draw_sprite(uint8_t x, uint8_t y, uint8_t *sprite, uint8_t n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((sprite[i] & (MASK >> j)) != 0)
            {
                if (display[(x + j) + (y + i) * CPU_SCREEN_WIDTH] == 1)
                {
                    display[(x + j) + (y + i) * CPU_SCREEN_WIDTH] = 0;
                }
                else
                {
                    display[(x + j) + (y + i) * CPU_SCREEN_WIDTH] = 1;
                }
            }
        }
    }
}

void cpu_display::print_display()
{
    for (int i = 0; i < CPU_SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < CPU_SCREEN_WIDTH; j++)
        {
            if (display[j + i * CPU_SCREEN_WIDTH] == 1)
            {
                std::cout << "X";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}