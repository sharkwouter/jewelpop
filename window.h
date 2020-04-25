#pragma once

#include <string>
#include <SDL2/SDL.h>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void handleEvents();
    void draw();
    inline bool isClosed() const { return _closed; }

private:
    bool init();

private:
    std::string _title;
    int _width = 800;
    int _height = 600;

    bool _closed = false;

    SDL_Event _event;

    SDL_Window * _window = nullptr;
    SDL_Renderer * _renderer = nullptr;
};