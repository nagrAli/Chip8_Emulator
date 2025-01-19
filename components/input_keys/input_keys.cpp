#include "input_keys.hpp"

input::input():key_map(std::make_unique<uint8_t[]>(TOTAL_KEYS))
{
    // do nothing
}

std::unique_ptr<uint8_t[]>& input::get_key_map()
{
    return key_map;
}