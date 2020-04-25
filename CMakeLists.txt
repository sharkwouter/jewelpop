cmake_minimum_required(VERSION 3.16)

project(Breakdown)

find_package(SDL2 REQUIRED)
add_executable(breakdown main.cpp window.cpp)
target_link_libraries(breakdown SDL2)
