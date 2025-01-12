#include <iostream>
#include <vector>
#include <functional>
#include "instruction_0xxx.hpp"
#include "instruction_1xxx.hpp"
#include "instruction_2xxx.hpp"
#include "instruction_3xxx.hpp"
#include "instruction_4xxx.hpp"
#include "instruction_5xxx.hpp"
#include "instruction_6xxx.hpp"
#include "instruction_7xxx.hpp"
#include "instruction_8xxx.hpp"
#include "instruction_9xxx.hpp"
#include "instruction_Axxx.hpp"
#include "instruction_Bxxx.hpp"
#include "instruction_Cxxx.hpp"
#include "instruction_Dxxx.hpp"
#include "instruction_Exxx.hpp"
#include "instruction_Fxxx.hpp"

typedef enum
{
    INSTRUCTION_0XXX = 0x00,
    INSTRUCTION_1XXX = 0x01,
    INSTRUCTION_2XXX = 0x02,
    INSTRUCTION_3XXX = 0x03,
    INSTRUCTION_4XXX = 0x04,
    INSTRUCTION_5XXX = 0x05,
    INSTRUCTION_6XXX = 0x06,
    INSTRUCTION_7XXX = 0x07,
    INSTRUCTION_8XXX = 0x08,
    INSTRUCTION_9XXX = 0x09,
    INSTRUCTION_AXXX = 0x0A,
    INSTRUCTION_BXXX = 0x0B,
    INSTRUCTION_CXXX = 0x0C,
    INSTRUCTION_DXXX = 0x0D,
    INSTRUCTION_EXXX = 0x0E,
    INSTRUCTION_FXXX = 0x0F,
    INSTRUCTION_MAX  = 0x10
}chip8_instruction_opcodes_t;

using callback_function_type = void (*)(chip8_cpu_components *components, uint16_t instruction);

class Instructions
{
    private:
        std::vector<callback_function_type> instruction_callback_table;
    public:
        Instructions();
        void execute_instruction(chip8_cpu_components *components, uint16_t instruction);
};