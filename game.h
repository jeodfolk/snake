#include <iostream>
#include <SDL/SDL.h>
#pragma once

class MainGame
    {
    public:
        MainGame();
        ~MainGame();

        void run();
        void initSystems();
    };