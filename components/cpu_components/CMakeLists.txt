add_library(cpu_components INTERFACE)
target_include_directories(cpu_components INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cpu_components INTERFACE index_register memory_chip8 program_counter registers stack_chip8 timer_chip8 cpu_display cpu_keypad cpu_sound_timer)
