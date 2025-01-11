#ifndef _MEMORY_CHIP8_HPP_
#define _MEMORY_CHIP8_HPP_

#include <iostream>
#include <memory>
#include <cstdint>

constexpr uint16_t MEMORY_SIZE = 4096U;
constexpr uint16_t INSTRUCTIONS_START_ADDRESS = 0x200;
constexpr uint16_t INSTRUCTIONS_END_ADDRESS = 0xFFF;
constexpr uint16_t CHARACTER_START_ADDRESS = 0x050;
constexpr uint16_t CHARACTER_END_ADDRESS = 0x0A0;
constexpr uint8_t INVALID_ADDRESS = 0x0000;

class memory_chip_8
{
    private:
    std::unique_ptr<uint8_t[]> memory_rom;
    public:
    memory_chip_8();
    void write_instruction(uint16_t address, uint8_t value);
    uint8_t read_instruction(uint16_t address);
    void write_character(uint16_t address, uint8_t value);
    uint8_t read_character(uint16_t address);
};
#endif