#ifndef _CPU_DISPLAY_
#define _CPU_DISPLAY_

#include <iostream>
#include <memory>

constexpr uint16_t CPU_SCREEN_WIDTH = 64;
constexpr uint16_t CPU_SCREEN_HEIGHT = 32;

class cpu_display
{
    private:
        std::unique_ptr<uint8_t[]> display;
    public:
        cpu_display();
        void clear_display();
        void invert_pixel(uint8_t x, uint8_t y);
        void set_pixel(uint8_t x, uint8_t y, uint8_t value);
        uint8_t get_pixel(uint8_t x, uint8_t y);
        void draw_sprite(uint8_t x, uint8_t y, uint8_t *sprite, uint8_t n);
        void print_display();
};
#endif 