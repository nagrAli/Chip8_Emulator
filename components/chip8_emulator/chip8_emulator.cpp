#include "chip8_emulator.hpp"
#include <iostream>

constexpr uint16_t ROM_START_ADDRESS = 0x200;
constexpr uint16_t ROM_END_ADDRESS = 0xFFF;
constexpr uint8_t  INTSRUCTION_SHIFT = 8u;
chip8_emulator::chip8_emulator(std::string rom_path)
{
    uint8_t status = load_rom(rom_path);
    if(status == 0)
    {
        std::cout << "ROM loaded successfully" << std::endl;
    }
    else
    {
        std::cout << "Error loading ROM" << std::endl;
        exit(1);
    }
    load_fontset();
}

void chip8_emulator::load_fontset()
{
    for(int i = 0; i < FONTSET_SIZE; i++)
    {
        components.memory_chip8.write_instruction(FONTSET_START_ADDRESS + i, font_set[i]);
    }
}
uint8_t chip8_emulator::load_rom(std::string rom_path)
{
    std::ifstream rom_file(rom_path, std::ios::binary);
    if(!rom_file.is_open())
    {
        return 1;
    }

    rom_file.seekg(0, std::ios::end);
    std::streampos rom_size = rom_file.tellg();
    rom_file.seekg(0, std::ios::beg);
    rom_size_emu = rom_size + ROM_START_ADDRESS;
    if(rom_size > (ROM_END_ADDRESS - ROM_START_ADDRESS))
    {
        return 2;
    }

    for(int i = 0; i < rom_size; i++)
    {
        uint8_t byte = static_cast<uint8_t>(rom_file.get());
        components.memory_chip8.write_instruction(ROM_START_ADDRESS + i, byte);
    }
    rom_file.close();
    return 0;
}
void chip8_emulator::run()
{
    components.program_counter_chip8 = ROM_START_ADDRESS;
    while(components.program_counter_chip8 < rom_size_emu)
    {
        uint8_t msb = components.memory_chip8.read_instruction(components.program_counter_chip8);
        uint8_t lsb = components.memory_chip8.read_instruction(components.program_counter_chip8 + 1);
        uint16_t instruction = (static_cast<uint16_t>(msb) << INTSRUCTION_SHIFT) | static_cast<uint16_t>(lsb);

        components.program_counter_chip8 += 2;

        instructions.execute_instruction(&components, instruction);
        display.update_screen(components.display_chip8.display);

        if(components.timer_chip8 > 0)
        {
            components.timer_chip8 = components.timer_chip8 - 1;
        }
        else
        {
            // do nohting
        }

        if(components.sound_timer_chip8 > 0)
        {
            components.sound_timer_chip8 = components.sound_timer_chip8 - 1;
        }
        else
        {
            // do nohting
        }
    }

}