#include <instruction_0xxx.hpp>

constexpr uint16_t INSTR_CLS = 0x00E0;
constexpr uint16_t INSTR_RET = 0x00EE;

void instruction_0xxx::return_from_subroutine(chip8_cpu_components *components)
{
    if(components != NULL)
    {
        uint16_t val = components->stack_chip8.pop_from_call_stack();
        if(val != INVALID_PC)
        {
            components->program_counter_chip8 = val;
        }
        else
        {
            // do nothing
        }
    }
    else
    {
        // do nothing
    }
}

void instruction_0xxx::clear_screen(chip8_cpu_components *components)
{
    if(components != NULL)
    {
        components->display_chip8.clear_display();
    }
    else
    {
        // do nothing
    }
}

void instruction_0xxx::callback(chip8_cpu_components *components, uint16_t instruction)
{
    switch(instruction)
    {
        case INSTR_CLS:
            // clear screen
            clear_screen(components);
            break;
        case INSTR_RET:
            // Return from a subroutine
            return_from_subroutine(components);
            break;
        default:
            std::cout<<"instruction_0xxx: Invalid Opcode\n";
    }
}