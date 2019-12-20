#include <iostream>
#include <vector>
#pragma once

class MainGame
    {
    public:
        MainGame();
        MainGame(int width, int height);
        ~MainGame();

        void run();
        void initSystems();
        void showScreen();
    
    private:
        int snakePosX;
        int snakePosY;

        int screenWidth = 15;
        int screenHeight = 50;
    };