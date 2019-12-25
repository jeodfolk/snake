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
    apple = 526;

    Snake *firstSeg = new Snake(NULL, NULL, char(254), 500);
    head = firstSeg;

    for(int i=0; i<1000; i++)
        {
        map[i] = ' ';
        }
    map[snakePos] = firstSeg->design;
    map[apple] = char(233);
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
        if(map[apple] == head->design)
            {
            collision();
            genApple();
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
        if(map[apple] == head->design)
            {
            collision();
            genApple();
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
        if(map[apple] == head->design)
            {
            collision();
            genApple();
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
        if(map[apple] == head->design)
            {
            collision();
            genApple();
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
        if(map[apple] == head->design)
            {
            collision();
            genApple();
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
    if(apple == 526)
        {
        Snake *newSeg = new Snake(head, NULL, char(254), );
        head->prevSeg = newSeg;
        map[snakePos] = newSeg->design;
        }
    else
        {
        Snake *newSeg = new Snake(head, head->prevSeg, char(254));
        newSeg->prevSeg->nextSeg = newSeg;
        map[snakePos] = newSeg->design;
        }
    }

void MainGame::genApple()
    {
    srand(time(NULL));
    while(1)
        {
        apple = rand()%1000;
        if(map[apple] == ' ' && apple%2 == 0)
            {
            map[apple] = char(233);
            return;
            }
        }
    }


