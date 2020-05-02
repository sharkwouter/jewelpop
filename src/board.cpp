//
// Created by wouter on 4/25/20.
//

#include "board.hpp"

Board::Board() {
    _selectionBox.w = Constants::blockSize - 1;
    _selectionBox.h = Constants::blockSize - 1;
    fillBoard();
    setBoardMeasurements();
}

void Board::fillBoard() {
    for (auto & x : _board) {
        for (int & y : x) {
            y = rand() % Jewels::jewels;
        }
    }
}

void Board::setBoardMeasurements() {
    this->_end_x = Constants::blockSize * Constants::board_width + Constants::offset_x;
    this->_end_y = Constants::blockSize * Constants::board_height + Constants::offset_y;;
}

Board::~Board() {

}

void Board::handleEvents(SDL_Event &event) {
    switch (event.type) {
        case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                move_selection(0, -1);
                break;
            case SDLK_DOWN:
                move_selection(0, 1);
                break;
            case SDLK_LEFT:
                move_selection(-1, 0);
                break;
            case SDLK_RIGHT:
                move_selection(1, 0);
                break;
        }
        break;
        case SDL_JOYBUTTONDOWN:
            //This case if for the PSP
            switch (event.jbutton.button) {
            case 6: //down
                move_selection(0, 1);
                break;
            case 7: //left
                move_selection(-1, 0);
                break;
            case 8: //up
                move_selection(0, -1);
                break;
            case 9: //right
                move_selection(1, 0);
                break;
            default:
                break;
        }
        break;
    }

    _selectionBox.x = _selection_x * Constants::blockSize + Constants::offset_x + 1;
    _selectionBox.y = _selection_y * Constants::blockSize + Constants::offset_y + 1;
}

void Board::move_selection(int x, int y) {
    _selection_x += x;
    _selection_y += y;

    if (_selection_x < 0)
        _selection_x = 0;
    if (_selection_x > Constants::board_width - 1)
        _selection_x = Constants::board_width - 1;
    if (_selection_y < 0)
        _selection_y = 0;
    if (_selection_y > Constants::board_height - 1)
        _selection_y = Constants::board_height - 1;
}


void Board::draw() {
    //Draw board lines
    SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
    for (int x = 0; x <= Constants::board_width; x++) {
        int current_x = Constants::offset_x + x * Constants::blockSize;
        SDL_RenderDrawLine(
                Window::renderer,
                current_x,
                Constants::offset_y,
                current_x,
                _end_y
                );
    }
    for (int y = 0; y <= Constants::board_height; y++) {
        int current_y = Constants::offset_y + y*Constants::blockSize;
        SDL_RenderDrawLine(
                Window::renderer,
                Constants::offset_x,
                current_y,
                _end_x,
                current_y
        );
    }

    //Draw selection box
    SDL_SetRenderDrawColor(Window::renderer, 0, 200, 255, 255);
    SDL_RenderFillRect(Window::renderer, &_selectionBox);

    //Draw jewels
    for (int x = 0;x < Constants::board_width; ++x) {
        for (int y = 0;y < Constants::board_height; ++y) {
            switch (_board[x][y]) {
                case Jewels::red:
                    SDL_SetRenderDrawColor(Window::renderer, 255, 0, 0, 255);
                    break;
                case Jewels::orange:
                    SDL_SetRenderDrawColor(Window::renderer, 255, 255, 0, 255);
                    break;
                case Jewels::green:
                    SDL_SetRenderDrawColor(Window::renderer, 0, 255, 0, 255);
                    break;
                case Jewels::blue:
                    SDL_SetRenderDrawColor(Window::renderer, 0, 0, 255, 255);
                    break;
                default:
                    SDL_SetRenderDrawColor(Window::renderer, 0, 0, 0, 255);
                    break;
            };
            SDL_Rect jewel;
            jewel.x = x * Constants::blockSize + Constants::offset_x + 6;
            jewel.y = y * Constants::blockSize + Constants::offset_y  + 6;
            jewel.w = Constants::blockSize - 12;
            jewel.h = Constants::blockSize - 12;

            SDL_RenderFillRect(Window::renderer, &jewel);
        }
    }
}