#pragma once
#include "Window.h"

enum gameState
{
    running,
    quit
};

class Game
{
public:
    Game();
    
    void Start();
    void Run();

private:
    Window _window;
    gameState _state;
};
