cmake_minimum_required(VERSION 3.10)

project(Jewelpop)

add_executable(jewelpop src/main.cpp src/window.cpp src/board.cpp src/constants.hpp src/jewels.hpp)

IF(PLATFORM_PSP)
    target_link_libraries(jewelpop PRIVATE SDL2main SDL2 ${PSP_LIBRARIES})
    create_pbp_file(
            TARGET jewelpop
            ICON_PATH NULL
            BACKGROUND_PATH NULL
            PREVIEW_PATH NULL
            TITLE Jewelpop
    )
ELSE()
    target_link_libraries(jewelpop PRIVATE SDL2main SDL2)
ENDIF()