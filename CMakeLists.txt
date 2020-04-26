cmake_minimum_required(VERSION 3.10)

project(Jewelpop)

#find_package(SDL2 REQUIRED)
add_executable(jewelpop main.cpp window.cpp board.cpp constants.hpp jewels.hpp)
target_link_libraries(jewelpop -lSDL2)
