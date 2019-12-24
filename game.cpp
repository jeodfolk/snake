#include <iostream>
#include <stdio.h>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"

using namespace std;
#define KEY_ARROW_CHAR1 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

MainGame::MainGame()
    {
    mapHeight = 20;
    mapWidth = 50;
    snakePos = (mapHeight*mapWidth)/2;
    map = new char [20*50];
    for(int i=0; i<1000; i++)
        {
        map[i] = ' ';
        }
    map[snakePos] = char(254);
    cout << map[snakePos] << endl;
    return;
    }

MainGame::~MainGame()
    {
    return;
    }

void MainGame::run()
    {
    int ch;
    while(true)
        {
        display();
        ch = getInput();
        Sleep(500);
        if(ch == KEY_DOWN)
            {
            map[snakePos] = ' ';
            snakePos = snakePos+2;
            map[snakePos] = char(254);
            }
        else if(ch == KEY_UP)
            {
            map[snakePos] = ' ';
            snakePos = snakePos+2;
            map[snakePos] = char(254);
            }
        else if(ch == KEY_LEFT)
            {
            map[snakePos] = ' ';
            snakePos = snakePos+2;
            map[snakePos] = char(254);
            }
        else if(ch == KEY_RIGHT)
            {
            map[snakePos] = ' ';
            snakePos = snakePos+2;
            map[snakePos] = char(254);
            }
        system("cls");
        }
    }

void MainGame::display()
    {
    //Screen setup
    int count = 0;
    //top
    cout << ' ';
    for(int i=0; i<mapWidth; i++)
        {
        cout << char(95);
        }
    cout << endl;
    //body
    for(int j=0; j<mapHeight; j++)
        {
        //l side
        cout << char(186);
        for(int i=0; i<mapWidth; i++)
            {
            cout << map[count];
            count++;
            }
        //r side
        cout << char(186);
        cout << endl;
    //bottom
        }
    cout << ' ';
    for(int i=0; i<mapWidth; i++)
        {
        cout << char(196);
        }

    }

int MainGame::getInput()
    {
    while(1)
        {
        if (kbhit())
            {
            if(!getch())
                {
                return getch();
                }
            }
        else
            {
            return -1;
            }
        }
    }



