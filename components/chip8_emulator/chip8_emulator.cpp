#include "chip8_emulator.hpp"

constexpr uint16_t ROM_START_ADDRESS = 0x200;
constexpr uint16_t ROM_END_ADDRESS = 0xFFF;

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

    if(rom_size > (ROM_END_ADDRESS - ROM_START_ADDRESS))
    {
        return 2;
    }

    // rom_file.read(reinterpret_cast<char*>(&components.memory[ROM_START_ADDRESS]), rom_size);
    for(int i = 0; i < rom_size; i++)
    {
        uint8_t byte = static_cast<uint8_t>(rom_file.get());
        components.memory_chip8.write_instruction(ROM_START_ADDRESS + i, byte);
    }
    rom_file.close();
    return 0;
}