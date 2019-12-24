#include <iostream>
#include <stdio.h>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"

using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

MainGame::MainGame()
    {
    mapHeight = 20;
    mapWidth = 50;
    direction = 2;
    snakePos = (mapHeight*mapWidth)/2;
    map = new char [20*50];

    Snake *firstSeg = new Snake;
    firstSeg->design = char(254);
    firstSeg->nextSeg = NULL;
    firstSeg->prevSeg = NULL;
    head = firstSeg;

    for(int i=0; i<1000; i++)
        {
        map[i] = ' ';
        }
    map[snakePos] = firstSeg->design;
    map[525] = char(233);
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
        system("cls");
        display();
        ch = getInput();
        Sleep(500);
        movement(ch);
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

void MainGame::movement(int ch)
    {
    if(ch == KEY_DOWN)
        {
        if(map[snakePos] == char(233))
            {
            collision();
            }
        else
            {
            map[snakePos] = ' ';
            }
        snakePos = snakePos+mapWidth;
        map[snakePos] = char(254);
        direction = mapWidth;
        }
    else if(ch == KEY_UP)
        {
        if(map[snakePos] == char(233))
            {
            collision();
            }
        else
            {
            map[snakePos] = ' ';
            }
        
        snakePos = snakePos-mapWidth;
        map[snakePos] = char(254);
        direction = -mapWidth;
        }
    else if(ch == KEY_LEFT)
        {
        if(map[snakePos] == char(233))
            {
            collision();
            }
        else
            {
            map[snakePos] = ' ';
            }
        snakePos = snakePos-2;
        map[snakePos] = char(254);
        direction = -2;
        }
    else if(ch == KEY_RIGHT)
        {
        if(map[snakePos] == char(233))
            {
            collision();
            }
        else
            {
            map[snakePos] = ' ';
            }
        snakePos = snakePos+2;
        map[snakePos] = char(254);
        direction = 2;
        }
    else
        {
        if(map[snakePos] == char(233))
            {
            collision();
            }
        else
            {
            map[snakePos] = ' ';
            }
        snakePos = snakePos + direction;
        map[snakePos] = char(254); 
        } 
    }

void MainGame::collision()
    {
    Snake *newSeg = new Snake;
    newSeg->nextSeg = head;
    char design = newSeg->design = char(254);
    map[snakePos] = design;
    }


