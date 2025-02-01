#include "instruction_Dxxx.hpp"

constexpr uint8_t REG_ADDR = 0x0F;
constexpr uint16_t VX_MASK = 0x0F00;
constexpr uint16_t VY_MASK = 0x00F0;
constexpr uint16_t N_MASK  = 0x000F;
constexpr uint8_t VX_SHIFT = 8u;
constexpr uint8_t VY_SHIFT = 4u;
constexpr uint8_t SPRITE_MASK = 0x80;
constexpr uint8_t SPRITE_LENGTH = 8;
constexpr uint8_t DISPLAY_WIDTH = 64;
constexpr uint8_t DISPLAY_HEIGHT = 32;

void instruction_Dxxx::draw_sprite(chip8_cpu_components *components, uint16_t instruction)
{
    uint8_t vx = (instruction & VX_MASK) >> VX_SHIFT;
    uint8_t vy = (instruction & VY_MASK) >> VY_SHIFT;
    uint8_t x = components->register_chip8.get_register_value(vx) % DISPLAY_WIDTH;
    uint8_t y = components->register_chip8.get_register_value(vy) % DISPLAY_HEIGHT;
    uint8_t height = instruction & N_MASK;
    uint8_t pixel = 0;

    components->register_chip8.set_register_value(REG_ADDR, 0);

    for (int yline = 0; yline < height; yline++)
    {
        pixel = components->memory_chip8.read_character(components->index_register_chip8 + yline);
        for (int xline = 0; xline < SPRITE_LENGTH; xline++)
        {
            if ((pixel & (SPRITE_MASK >> xline)) != 0)
            {
                if (components->display_chip8.get_pixel(x + xline, y + yline) == 1)
                {
                    components->register_chip8.set_register_value(REG_ADDR, 1);
                }
                components->display_chip8.invert_pixel(x + xline, y + yline);
            }
        }
    }
}

void instruction_Dxxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    draw_sprite(components, instruction);
}