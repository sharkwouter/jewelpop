cmake_minimum_required(VERSION 3.10)

project(Breakdown)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# find_package(SDL2 REQUIRED)
add_executable(breakdown main.cpp window.cpp board.cpp constants.hpp jewels.hpp)
target_link_libraries(breakdown -lSDL2)
