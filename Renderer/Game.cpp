#include <iostream>
#include <gl\glew.h>

#include "Game.h"

Game::Game()
{
}

int Game::Run()
{
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
        SDL_GL_SwapWindow(window.GetSDLWindow());
    }
}

Game::~Game()
{
}
