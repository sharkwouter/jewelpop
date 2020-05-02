cmake_minimum_required(VERSION 3.10)

project(Jewelpop)

add_executable(jewelpop main.cpp window.cpp board.cpp constants.hpp jewels.hpp)
target_link_libraries(jewelpop PRIVATE -lSDL2main -lSDL2)

IF(PLATFORM_PSP)
    create_pbp_file(
            TARGET jewelpop
            ICON_PATH NULL
            BACKGROUND_PATH NULL
            PREVIEW_PATH NULL
    )
ENDIF()