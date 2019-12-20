#include <iostream>
#include <stdio.h>
#include <vector>
#include "game.h"

#ifndef UNICODE
#define UNICODE
#define UNICODE_WAS_UNDEFINED
#endif
#include <Windows.h>



MainGame::MainGame()
    {
    snakePosX = 0;
    snakePosY = 0;
    int screenWidth = 15;
    int screenHeight = 50;
    return;
    }

MainGame::~MainGame()
    {
    return;
    }

void MainGame::run()
    {
    initSystems();
    }

void MainGame::initSystems()
    {
        int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;
    wchar_t *screen = new wchar_t[screenWidth*screenHeight];
	for (int i = 0; i < screenWidth*screenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

    pField = new unsigned char[nFieldWidth*nFieldHeight]; // Create play field buffer
	for (int x = 0; x < nFieldWidth; x++) // Board Boundary
		for (int y = 0; y < nFieldHeight; y++)
			pField[y*nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
    while(true)
        {
        WriteConsoleOutputCharacter(hConsole, screen, screenWidth * screenHeight, { 0,0 }, &dwBytesWritten);
        }
    }

void MainGame::showScreen()
    {

    }

#ifdef UNICODE_WAS_UNDEFINED
#undef UNICODE
#endif