#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

int main(int argc, char** argv)
{
    //Initialise SDL2 and check it initialised successfully
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        return 1;
    }

    //Create an SDL window
    SDL_Window* window = SDL_CreateWindow("Renderer", 100, 100, 640, 480, SDL_WINDOW_OPENGL);

    //Check window was created 
    if (window == nullptr)
    {
        std::cout << "SDL_Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        return 1;
    }

    //Create an opengl context for our window
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    //Check context was created
    if (glContext == nullptr)
    {
        std::cout << "SDL_CreateContext Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::cin.get();
        return 1;
    }

    //Initialise opengl using glew
    GLenum error = glewInit();

    //Check opengl was initialised successfully
    if (error != GLEW_OK)
    {
        std::cout << "glewInit failed" << std::endl;
    }

    //Tell sdl to use a double buffer for rendering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //set the clear colour for the window
    glClearColor(0, 0, 0, 1);

    //Game Loop
    while (true)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            SDL_Quit();
            return 0;
        }
        SDL_GL_SwapWindow(window);
    }
    return 0;
}