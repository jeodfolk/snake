#include <iostream>
#include <stdio.h>
#include <vector>
#include <Windows.h>
#include <ctime>
#include "game.h"

using namespace std;

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
    map[snakePos] = char(219);
    cout << map[snakePos] << endl;
    return;
    }

MainGame::~MainGame()
    {
    return;
    }

void MainGame::run()
    {
    while(true)
        {
        display();
        Sleep(2000);
        system("cls");
        }
    }

void MainGame::display()
    {
    //Screen setup
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
            cout << map[i];
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



