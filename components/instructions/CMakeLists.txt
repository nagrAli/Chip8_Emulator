add_library(instructions instructions.cpp instruction_0xxx.cpp 
                                          instruction_1xxx.cpp 
                                          instruction_2xxx.cpp 
                                          instruction_3xxx.cpp 
                                          instruction_4xxx.cpp
                                          instruction_5xxx.cpp
                                          instruction_6xxx.cpp
                                          instruction_7xxx.cpp
                                          instruction_8xxx.cpp
                                          instruction_9xxx.cpp
                                          instruction_Axxx.cpp
                                          instruction_Bxxx.cpp
                                          instruction_Cxxx.cpp
                                          )
target_include_directories(instructions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(instructions PRIVATE cpu_components)

