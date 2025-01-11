cmake_minimum_required(VERSION 3.5)

project(Chip_8_Emulator VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Chip_8_Emulator main/main.cpp)

add_subdirectory(components/registers)
add_subdirectory(components/memory_chip8)
add_subdirectory(components/index_register)
add_subdirectory(components/program_counter)
add_subdirectory(components/stack_chip8)
add_subdirectory(components/timer)
add_subdirectory(components/input_keys)
add_subdirectory(components/cpu_components)
add_subdirectory(components/instructions)


target_link_libraries(Chip_8_Emulator PRIVATE registers memory_chip8 index_register program_counter stack_chip8 timer input_keys cpu_components instructions)

