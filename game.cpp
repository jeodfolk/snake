#include <iostream>
#include <stdio.h>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"
 #include <fstream>

using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define STATE_TAIL_MOVE 'A'
#define STATE_TAIL_NO_MOVE 'B'
#define STATE_TAIL_BODY_MOVE 'C'

MainGame::MainGame()
    {
    mapHeight = 20;
    mapWidth = 50;
    direction = 2;
    map = new char [20*50];
    apple = 526;
    state = STATE_TAIL_MOVE;

    Snake *firstSeg = new Snake(NULL, NULL, char(254), 500);
    head = firstSeg;
    tail = firstSeg;
    tail->nextSeg = head;

    for(int i=0; i<1000; i++)
        {
        map[i] = ' ';
        }
    map[head->coord] = firstSeg->design;
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
    ofstream afile;
    afile.open("data.txt");
    while(true)
        {
        system("cls");
        display();
        ch = getInput();
        Sleep(500);
        movement(ch, afile);
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

void MainGame::movement(int ch, ofstream &sfile)
    {
    int coord = head->coord;
    if(ch == KEY_DOWN)
        {
        if(map[apple] == head->design)
            {
            collision();
            genApple();
            }
        coord = coord+mapWidth;
        direction = mapWidth;
        }
    else if(ch == KEY_UP)
        {
        if(map[apple] == head->design)
            {
            collision();
            genApple();
            }
        coord = coord-mapWidth;
        direction = -mapWidth;
        }
    else if(ch == KEY_LEFT)
        {
        if(map[apple] == head->design)
            {
            collision();
            genApple();
            }
        coord = coord-2;
        direction = -2;
        }
    else if(ch == KEY_RIGHT)
        {
        if(map[apple] == head->design)
            {
            collision();
            genApple();
            }
        coord = coord+2;
        direction = 2;
        }
    else
        {
        if(map[apple] == head->design)
            {
            collision();
            genApple();
            }
        coord = coord + direction;
        } 
    

    // if(!flag)
    //     {
    //     map[tail->coord] = ' ';
    //     tail->coord = tail->nextSeg->coord;
    //     head->coord = coord;
    //     }
    // else
    //     {
    //     head->prevSeg->coord = head->coord;
    //     tail->coord = tail->nextSeg->coord;
    //     head->coord = coord;
    //     }   
    
    switch(state)
        {
        case STATE_TAIL_MOVE:
                sfile<<"tail move " << state << endl;
            map[tail->coord] = ' ';
            tail->coord = tail->nextSeg->coord;
            head->coord = coord;
            break;
        case STATE_TAIL_NO_MOVE:
                sfile<<"tail no move " << state << endl;
            head->prevSeg->coord = head->coord;
            head->coord = coord;
            state = STATE_TAIL_BODY_MOVE;
            break;
        case STATE_TAIL_BODY_MOVE:
                sfile<<"tailbody move " << state << endl;
            map[tail->coord] = ' ';
            head->prevSeg->coord = head->coord;
            tail->coord = tail->nextSeg->coord;
            head->coord = coord;
            break;
        default:
            break;
        }
        
    Snake *temp = head;
    while(temp)
        {
        map[temp->coord] = char(254);
        temp = temp->prevSeg;
        }
    }

void MainGame::collision()
    {
    if(apple == 526)
        {
        Snake *newSeg = new Snake(head, NULL, char(254), head->coord);
        head->prevSeg = newSeg;
        map[head->coord] = newSeg->design;
        tail = newSeg;
        }
    else
        {
        Snake *newSeg = new Snake(head, head->prevSeg, char(254), head->coord);
        newSeg->prevSeg->nextSeg = newSeg;
        head->prevSeg = newSeg;
        map[head->coord] = newSeg->design;
        state = STATE_TAIL_NO_MOVE;
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


