#ifndef _CPU_KEYPAD_
#define _CPU_KEYPAD_

#include <iostream>
#include <memory>

const uint8_t KEYPAD_SIZE_KEY= 16;
class cpu_keypad
{
    private:
        std::unique_ptr<uint8_t[]> keys;
    public:
        cpu_keypad();
        void set_key(uint8_t key, uint8_t val);
        uint8_t get_key(uint8_t key) const;
        std::unique_ptr<uint8_t[]>& get_key_map();
};
#endif