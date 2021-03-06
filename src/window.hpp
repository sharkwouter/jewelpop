#ifndef JEWELPOP_WINDOW_H
#define JEWELPOP_WINDOW_H

#include <string>
#include <SDL2/SDL.h>

class Window {
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void handleEvents(SDL_Event &event);
    void clear();
    inline bool isClosed() const { return _closed; }

private:
    bool init();

public:
    static SDL_Renderer * renderer;

private:
    std::string _title;
    int _width = 800;
    int _height = 600;

    bool _closed = false;

    SDL_Color _backgroundColor{255, 255, 255, 255};

    SDL_Window * _window = nullptr;

    SDL_Joystick *_joystick = nullptr;
};

#endif //JEWELPOP_WINDOW_H