#include <iostream>
#include <gl\glew.h>

#include "Game.h"

Game::Game()
{
}

int Game::Start()
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

    _state = gameState::running;
    Run();

    return 0;
}

void Game::Run()
{
    //Game Loop
    while (_state == gameState::running)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            SDL_Quit();
            _state = gameState::quit;
        }

        SDL_GL_SwapWindow(_window.GetSDLWindow());
    }
}


