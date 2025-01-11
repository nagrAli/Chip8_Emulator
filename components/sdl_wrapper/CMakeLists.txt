add_library(sdl_wrapper sdl_display.cpp)
target_include_directories(sdl_wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})