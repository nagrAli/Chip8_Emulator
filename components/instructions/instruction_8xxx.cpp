#include "instruction_8xxx.hpp"

constexpr uint16_t SUB_OPCODE_MASK = 0x000F;
constexpr uint16_t INDEX_MASK_VX   = 0x0F00;
constexpr uint16_t INDEX_MASK_VY   = 0x00F0;
constexpr uint8_t  CARRY_REG       = 0x0F;
constexpr uint8_t  MAX_VAL_8BIT    = 0xFF;
constexpr uint8_t  SHIFT_REG_X     = 8u;
constexpr uint8_t  SHIFT_REG_Y     = 4u;

typedef enum
{
    SUB_OPCODE_0 = 0,
    SUB_OPCODE_1 = 1,
    SUB_OPCODE_2 = 2,
    SUB_OPCODE_3 = 3,
    SUB_OPCODE_4 = 4,
    SUB_OPCODE_5 = 5,
    SUB_OPCODE_6 = 6,
    SUB_OPCODE_7 = 7,
    SUB_OPCODE_8 = 8,
    SUB_OPCODE_9 = 9,
    SUB_OPCODE_A = 10,
    SUB_OPCODE_B = 11,
    SUB_OPCODE_C = 12,
    SUB_OPCODE_D = 13,
    SUB_OPCODE_E = 14,
    SUB_OPCODE_F = 15,
}instruction8x_subcodes_t;

void instruction_8xxx::perform_operation(chip8_cpu_components *components, uint16_t instruction)
{
    uint16_t sum = 0;
    uint8_t carry = 0;
    uint8_t sub_opcode  = (instruction & SUB_OPCODE_MASK);
    uint8_t index_reg_x = (instruction & INDEX_MASK_VX) >> SHIFT_REG_X; 
    uint8_t index_reg_y = (instruction & INDEX_MASK_VY) >> SHIFT_REG_Y;
    uint8_t vy = components->register_chip8.get_register_value(index_reg_y);
    uint8_t vx = components->register_chip8.get_register_value(index_reg_x);

    switch(sub_opcode)
    {
        case SUB_OPCODE_0:
            components->register_chip8.set_register_value(index_reg_x, vy);
            break;
        case SUB_OPCODE_1:
            components->register_chip8.set_register_value(index_reg_x, (vx | vy));
            break;
        case SUB_OPCODE_2:
            components->register_chip8.set_register_value(index_reg_x, (vx & vy));
            break;
        case SUB_OPCODE_3:
            components->register_chip8.set_register_value(index_reg_x, (vx ^ vy));
            break;
        case SUB_OPCODE_4:
            sum = vx + vy;
            carry = sum > MAX_VAL_8BIT ? 1 : 0;
            components->register_chip8.set_register_value(CARRY_REG, carry);
            components->register_chip8.set_register_value(index_reg_x, (sum & MAX_VAL_8BIT));
            break;
        case SUB_OPCODE_5:
            carry = vx > vy ? 1 : 0;
            components->register_chip8.set_register_value(CARRY_REG, carry);
            components->register_chip8.set_register_value(index_reg_x, (vx - vy));
            break;
        case SUB_OPCODE_6:
            components->register_chip8.set_register_value(CARRY_REG, (vx & 0x01));
            components->register_chip8.set_register_value(index_reg_x, (vx >> 1));
            break;
        case SUB_OPCODE_7:
            carry = vy > vx ? 1 : 0;
            components->register_chip8.set_register_value(CARRY_REG, carry);
            components->register_chip8.set_register_value(index_reg_x, (vy - vx));
            break;
        case SUB_OPCODE_E:
            components->register_chip8.set_register_value(CARRY_REG, ((vx & 0x80) >> 7));
            components->register_chip8.set_register_value(index_reg_x, (vx << 1));
            break;
        default:
            // do nothing
            break;
    } 
}

void instruction_8xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
   perform_operation(components, instruction); 
}