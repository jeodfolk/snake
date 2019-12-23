#include <iostream>
#include <vector>
#include <Windows.h>

#pragma once

class MainGame
    {
    public:
        MainGame();
        ~MainGame();

        void run();
        void display();

    private:
        int snakePos;
        int mapHeight;
        int mapWidth;
        char *map;

    };