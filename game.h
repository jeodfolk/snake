#include <iostream>
#include <vector>
#include <Windows.h>

#pragma once
struct Snake
    {
    Snake *nextSeg;
    Snake *prevSeg;
    char design;
    int coord;

    Snake(Snake *next, Snake *prev, char des, int pos): nextSeg(next),prevSeg(prev), 
                                                        design(des), coord(pos){}
    };

class MainGame
    {
    public:
        MainGame();
        ~MainGame();

        void run();
        void display();
        int getInput();
        void movement(int ch, std::ofstream &sfile);
        void collision();
        void genApple();

    private:
        Snake *head;
        Snake *tail;
        int mapHeight;
        int mapWidth;
        char *map;
        int direction;
        int apple;
        bool flag;
        char state;
    };