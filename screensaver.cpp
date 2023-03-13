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

void printB(HDC hDC, int x, int y, int kx, int ky);
void printG(HDC hDC, int x, int y, int kx, int ky);
void printW(HDC hDC, int x, int y, int kx, int ky);

void print_Head(HDC hDC, int *x, int *y, int *kx, int *ky);
void print_Body(HDC hDC, int *x, int *y, int *kx, int *ky);
void print_Arm(HDC hDC, int *x, int *y, int *kx, int *ky);
void print_Tail(HDC hDC, int *x, int *y, int *kx, int *ky);
void print_Face(HDC hDC, int *x, int *y, int *kx, int *ky);

void next_line(int *y, int *ky);

void view_screen()
{
	HDC hDC = GetDC(GetConsoleWindow());
	cursorVisible(handle_view);
	SelectObject(hDC, GetStockObject(DC_BRUSH));
	system("cls");
	int step_x = 110; 
	int step_kx = step_x + 100;
	int step = 10; // на сколько блоков идет вперед за кадр
	int speed = 30; // задержка обновления
    do
    {
		int y = 100;
		int ky = y + 10;

		int x = step_x;
		int kx = step_kx;

		if (x - 110 >= 920)
		{
			step_x = -220;
			step_kx = step_x + 100;
			x = step_x;
			kx = step_kx;

		}
		SetDCBrushColor(hDC, RGB(0, 126, 158));
		Rectangle(hDC, 0, 0, 1000, 1000); // фон
		
		print_Head(hDC, &x, &y, &kx, &ky);
		print_Body(hDC, &x, &y, &kx, &ky);
		print_Arm(hDC, &x, &y, &kx, &ky);
		print_Tail(hDC, &x, &y, &kx, &ky);
		print_Face(hDC, &x, &y, &kx, &ky);

        Sleep(speed); 
		step_x += step;
		step_kx += step;

		if (_kbhit()) {
			int key = _getch();
			if (key == ESC)
			{
				break;
			}
		}
	} while (TRUE);
    system("cls");
}

void printB(HDC hDC, int x, int y, int kx, int ky) {
	SetDCBrushColor(hDC, RGB(0, 0, 0));
	Rectangle(hDC, x, y, kx, ky);
}

void printG(HDC hDC, int x, int y, int kx, int ky) {
	SetDCBrushColor(hDC, RGB(192, 192, 192));
	Rectangle(hDC, x, y, kx, ky);
}

void printW(HDC hDC, int x, int y, int kx, int ky) {
	SetDCBrushColor(hDC, RGB(255, 255, 255));
	Rectangle(hDC, x, y, kx, ky);
}

void next_line(int* y, int* ky) {
	*y += 10;
	*ky += 10;
}

void print_Head(HDC hDC, int* x, int *y, int* kx, int *ky) {
	printB(hDC, *x, *y, *kx, *ky);
	*x -= 10;
	*kx += 20;
	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 20, *y, *kx - 20, *ky);

	*x -= 10;
	*kx += 10;
	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 10, *y, *kx - 10, *ky);
	printW(hDC, *x + 30, *y, *kx - 20, *ky);

	for (int j = 0; j < 2; j++)
	{
		*x -= 10;
		*kx += 10;
		next_line(*&y, *&ky);
		printB(hDC, *x, *y, *kx, *ky);
		printG(hDC, *x + 10, *y, *kx - 10, *ky);
		printW(hDC, *x + 20, *y, *kx - 20, *ky);
	}

	*x -= 10;
	*kx += 10;
	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 10, *y, *kx - 10, *ky);
	printW(hDC, *x + 20, *y, *kx - 20, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 10, *y, *kx - 10, *ky);
	printW(hDC, *x + 20, *y, *kx - 20, *ky);
}

void print_Body(HDC hDC, int* x, int* y, int* kx, int* ky) {
	*x -= 10;
	*kx += 10;
	for (int step = 0; step < 5; step++) { // лицо
		next_line(*&y, *&ky);
		printB(hDC, *x, *y, *kx, *ky);
		printG(hDC, *x + 10, *y, *kx - 10, *ky);
		printW(hDC, *x + 20, *y, *kx - 20, *ky);
	}
	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx + 10, *ky);
	printG(hDC, *x + 10, *y, *kx - 10, *ky);
	printW(hDC, *x + 20, *y, *kx - 20, *ky);
	
}

void print_Arm(HDC hDC, int* x, int* y, int* kx, int* ky) {
	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx + 20, *ky);
	printG(hDC, *x + 10, *y, *kx + 10, *ky);
	printW(hDC, *x + 20, *y, *kx - 20, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx + 20, *ky);
	printG(hDC, *x + 10, *y, *kx + 10, *ky);
	printW(hDC, *x + 20, *y, *kx, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x - 10, *y, *kx + 20, *ky);
	printB(hDC, *x - 40, *y, *x - 30, *ky);
	printG(hDC, *x, *y, *kx + 10, *ky);
	printW(hDC, *x + 10, *y, *kx - 20, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x - 50, *y, *kx + 20, *ky);
	printG(hDC, *x - 40, *y, *kx - 10, *ky);
	printB(hDC, *x - 30, *y, *x - 10, *ky);
	printW(hDC, *x, *y, *kx - 20, *ky);
}

void print_Tail(HDC hDC, int* x, int* y, int* kx, int* ky) {
	*x -= 50;
	*kx -= 10;

	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 10, *y, *x + 40, *ky);
	printW(hDC, *x + 40, *y, *kx - 10, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 10, *y, *kx - 10, *ky);
	printW(hDC, *x + 20, *y, *kx - 20, *ky);
	*kx -= 10;

	next_line(*&y, *&ky);
	printB(hDC, *x, *y, *kx, *ky);
	printG(hDC, *x + 10, *y, *kx - 10, *ky);
	printW(hDC, *x + 30, *y, *kx - 20, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x + 10, *y, *kx - 10, *ky);
	printG(hDC, *x + 30, *y, *kx - 20, *ky);
	printW(hDC, *x + 40, *y, *kx - 30, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x + 30, *y, *kx - 20, *ky);
	printG(hDC, *x + 40, *y, *kx - 30, *ky);
	printW(hDC, *x + 60, *y, *kx - 50, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x + 40, *y, *kx - 30, *ky);
	printG(hDC, *x + 60, *y, *kx - 50, *ky);

	next_line(*&y, *&ky);
	printB(hDC, *x + 50, *y, *kx - 50, *ky);
}

void print_Face(HDC hDC, int* x, int* y, int* kx, int* ky) {
	printB(hDC, *x + 150, *y - 160, *kx - 90, *ky - 130); // левый глаз
	printB(hDC, *x + 200, *y - 160, *kx - 40, *ky - 130); // правый глаз
	printB(hDC, *x + 200, *y - 100, *kx - 40, *ky - 90); // рот
}
