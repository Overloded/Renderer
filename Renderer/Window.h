#pragma once
#include <SDL\SDL.h>
class Window
{
public:
    Window();
    ~Window();

    SDL_Window* GetSDLWindow();
    void Resize(int height, int width);
private:
    SDL_Window *_SDLWindow;
    SDL_GLContext _glContext;
};

