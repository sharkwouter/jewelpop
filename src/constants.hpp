//
// Created by wouter on 4/26/20.
//

#ifndef JEWELPOP_CONSTANTS_HPP
#define JEWELPOP_CONSTANTS_HPP

#define GAME "Jewelpop"

namespace Constants {
    static int screen_width = 480;
    static int screen_height = 272;
    static const int board_width = 8;
    static const int board_height = 7;
    static int blockSize = screen_height/board_height;
    static int offset_y = (screen_height-(blockSize*board_height))/2;
    static int offset_x = offset_y;
}

#endif //JEWELPOP_CONSTANTS_HPP
