#include "cpu_keypad.hpp"

cpu_keypad::cpu_keypad()
{
    keys = std::make_unique<uint8_t[]>(KEYPAD_SIZE_KEY);
}

void cpu_keypad::set_key(uint8_t key, uint8_t val)
{
    keys[key] = val;
}

uint8_t cpu_keypad::get_key(uint8_t key) const
{
    return keys[key];
}

std::unique_ptr<uint8_t[]>& cpu_keypad::get_key_map()
{
    return keys;
}