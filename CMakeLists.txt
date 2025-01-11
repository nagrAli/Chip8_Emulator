cmake_minimum_required(VERSION 3.5)

project(Chip_8_Emulator VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

# Include SDL2 headers

add_executable(${PROJECT_NAME} main/main.cpp)

# Link SDL2 to your project

add_subdirectory(components/registers)
add_subdirectory(components/memory_chip8)
add_subdirectory(components/index_register)
add_subdirectory(components/program_counter)
add_subdirectory(components/stack_chip8)
add_subdirectory(components/timer)
add_subdirectory(components/input_keys)
add_subdirectory(components/cpu_components)
add_subdirectory(components/instructions)
add_subdirectory(components/sdl_wrapper)


target_link_libraries(${PROJECT_NAME} PRIVATE   registers 
                                                memory_chip8 
                                                index_register 
                                                program_counter 
                                                stack_chip8 timer 
                                                input_keys 
                                                cpu_components 
                                                instructions
                                                sdl_wrapper
                                                SDL2::SDL2)

if(MINGW)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/external_components/sdl2/SDL2.dll" $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()