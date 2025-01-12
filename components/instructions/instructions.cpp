#include "instructions.hpp"

constexpr uint16_t  INSTRUCTION_OPCODE_LENGTH = 16u;
constexpr uint16_t  INSTRUCTION_OPCODE_MASK   = 0xF000;
constexpr uint8_t   INSTRUCTION_OPCODE_SHIFT  = 12u;

Instructions::Instructions()
{
    instruction_callback_table.reserve(INSTRUCTION_OPCODE_LENGTH);
    instruction_callback_table[INSTRUCTION_0XXX] = &(instruction_0xxx::callback);
    instruction_callback_table[INSTRUCTION_1XXX] = &(instruction_1xxx::callback);
    instruction_callback_table[INSTRUCTION_2XXX] = &(instruction_2xxx::callback);
    instruction_callback_table[INSTRUCTION_3XXX] = &(instruction_3xxx::callback);
    instruction_callback_table[INSTRUCTION_4XXX] = &(instruction_4xxx::callback);
    instruction_callback_table[INSTRUCTION_5XXX] = &(instruction_5xxx::callback);
    instruction_callback_table[INSTRUCTION_6XXX] = &(instruction_6xxx::callback);
    instruction_callback_table[INSTRUCTION_7XXX] = &(instruction_7xxx::callback);
    instruction_callback_table[INSTRUCTION_8XXX] = &(instruction_8xxx::callback);
    instruction_callback_table[INSTRUCTION_9XXX] = &(instruction_9xxx::callback);
    instruction_callback_table[INSTRUCTION_AXXX] = &(instruction_Axxx::callback);
    instruction_callback_table[INSTRUCTION_BXXX] = &(instruction_Bxxx::callback);
    instruction_callback_table[INSTRUCTION_CXXX] = &(instruction_Cxxx::callback);
    instruction_callback_table[INSTRUCTION_DXXX] = &(instruction_Dxxx::callback);
    instruction_callback_table[INSTRUCTION_EXXX] = &(instruction_Exxx::callback);
    instruction_callback_table[INSTRUCTION_FXXX] = &(instruction_Fxxx::callback);
}

void Instructions::execute_instruction(chip8_cpu_components *components, uint16_t instruction)
{
    chip8_instruction_opcodes_t opcode = static_cast<chip8_instruction_opcodes_t>((instruction & INSTRUCTION_OPCODE_MASK) >> INSTRUCTION_OPCODE_SHIFT);
    if(opcode < INSTRUCTION_MAX && instruction_callback_table[opcode] != nullptr)
    {
        instruction_callback_table[opcode](components, instruction);
    }
    else
    {
        std::cerr << "Unknown instruction: " << instruction << std::endl;
    }
}
