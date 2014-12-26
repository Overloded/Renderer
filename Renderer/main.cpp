#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        std::cin.get();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Renderer", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "SDL_Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        return 1;
    }

    while (true)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            SDL_Quit();
            return 0;
        }
    }
    return 0;
}