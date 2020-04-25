cmake_minimum_required(VERSION 3.10)

project(Breakdown)

find_package(SDL2 REQUIRED)
add_executable(breakdown main.cpp window.cpp rect.cpp rect.h)
target_link_libraries(breakdown SDL2)
