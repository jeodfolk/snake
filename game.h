#include <iostream>
#include <vector>
#include <Windows.h>

#pragma once
struct Snake
    {
    Snake *nextSeg;
    Snake *prevSeg;
    char design;
    };

class MainGame
    {
    public:
        MainGame();
        ~MainGame();

        void run();
        void display();
        int getInput();
        void movement(int ch);
        void collision();

    private:
        Snake *head;
        int snakePos;
        int mapHeight;
        int mapWidth;
        char *map;
        int direction;
    };