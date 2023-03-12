#include "screensaver.h"
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"

#define ESC 27

HANDLE handle_view = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void view_screen()
{
	HDC hDC = GetDC(GetConsoleWindow());
    
	int x = 0;
	int y = 0;
	int kx = 200;
	int ky = 200;
	Rectangle(hDC, x, y, kx, ky);
    bool exit = false;
    do
    {
        system("cls");
        cursorVisible(handle_view);
        //Rectangle(hDC, x, y, kx, ky);
        Ellipse(hDC, x, y, kx, ky);
        double dx = 5;
        x += 5;
        kx += 5;
        Sleep(1);
    } while (!_kbhit());
    system("cls");
}
