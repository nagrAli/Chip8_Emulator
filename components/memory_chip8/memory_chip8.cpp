#include "memory_chip8.hpp"

memory_chip_8::memory_chip_8() : memory_rom(std::make_unique<uint8_t[]>(MEMORY_SIZE))
{
    std::cout<<"Memory constructor\n";
}

uint8_t memory_chip_8::read_instruction(uint16_t address)
{
    if(address >= INSTRUCTIONS_START_ADDRESS && address <= INSTRUCTIONS_END_ADDRESS)
        return memory_rom[address];
    else
        return INVALID_ADDRESS;
}

void memory_chip_8::write_instruction(uint16_t address, uint8_t value)
{
    if(address >= INSTRUCTIONS_START_ADDRESS && address <= INSTRUCTIONS_END_ADDRESS)
        memory_rom[address] = value;
}

uint8_t memory_chip_8::read_character(uint16_t address)
{
    if(address >= CHARACTER_START_ADDRESS && address <= CHARACTER_END_ADDRESS)
        return memory_rom[address];
    else
        return INVALID_ADDRESS;
}

void memory_chip_8::write_character(uint16_t address, uint8_t value)
{
    if(address >= INSTRUCTIONS_START_ADDRESS && address <= INSTRUCTIONS_END_ADDRESS)
        memory_rom[address] = value;
}