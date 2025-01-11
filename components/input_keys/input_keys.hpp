#ifndef _INPUT_KEYS_HPP_
#define _INPUT_KEYS_HPP_

#include<iostream>
#include<cstdint>
#include<memory>

constexpr uint8_t TOTAL_KEYS = 16;
class input
{
    private:
        std::unique_ptr<uint8_t[]>key_map;
    public:
        input();
};
#endif