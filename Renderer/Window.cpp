#include "Window.h"
#include <iostream>

Window::Window()
{
    //Initialise SDL2 and check it initialised successfully
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        exit(EXIT_FAILURE);
    }

    //create a default window
    _SDLWindow = SDL_CreateWindow("Renderer", 100, 100, 640, 480, SDL_WINDOW_OPENGL);

    //Check window was created 
    if (_SDLWindow == nullptr)
    {
        std::cout << "SDL_Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        exit(EXIT_FAILURE);
    }

    //Create an opengl context for our window
    _glContext = SDL_GL_CreateContext(_SDLWindow);

    //Check context was created
    if (_glContext == nullptr)
    {
        std::cout << "SDL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        exit(EXIT_FAILURE);
    }
}


Window::~Window()
{
    SDL_Quit();
}

SDL_Window* Window::GetSDLWindow()
{
    return _SDLWindow;
}
