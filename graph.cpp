#include "graph.h"
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <winuser.h>
#include <conio.h>
#include "menu.h"

#define a 1
#define b 2
#define ESC 27

HANDLE handle_graph = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;


double func1(double x) {
	return exp((-1) * x) * log(pow(x + 1, 0.5));
}

double func2(double x) {
	return x + sin(x);
}

void graphic()
{
	HDC hDC = GetDC(GetConsoleWindow());
	SetConsoleTitleA("Построение графиков функций");
	system("cls");
	int kx = 100;
	int ky = 100;
	int center_x = 150;
	int center_y = 350;
	double x;
	HPEN Pen_line = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	HPEN Pen_fun1 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN Pen_fun2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 255));
	bool exit = false;
	do
	{
		SelectObject(hDC, Pen_line);
		//x
		TextOutA(hDC, 750, center_y + 10, "X", 1);
		MoveToEx(hDC, 100, center_y, NULL);
		LineTo(hDC, 750, center_y);
		LineTo(hDC, 740, center_y - 5);
		MoveToEx(hDC, 750, center_y, NULL);
		LineTo(hDC, 740, center_y + 5);


		//y
		TextOutA(hDC, center_x - 20, 10, "Y", 1);
		MoveToEx(hDC, center_x, 10, NULL);
		LineTo(hDC, center_x, 400);
		MoveToEx(hDC, center_x, 10, NULL);
		LineTo(hDC, center_x + 5, 20);
		MoveToEx(hDC, center_x, 10, NULL);
		LineTo(hDC, center_x - 5, 20);



		TextOutA(hDC, center_x - 20, center_y + 10, "0", 1); // написание 0 на начале координат
		TextOutA(hDC, center_x + kx, center_y + 10, "1", 1); // написание 1 на оси OX
		TextOutA(hDC, center_x + kx * 2, center_y + 10, "2", 1); // написание 2 на оси OX


		SelectObject(hDC, Pen_fun1);

		TextOutA(hDC, center_x + b * kx + 10, center_y - func1(b) * ky - 20, "y = e^(-x)*lg((x+1)^0.5)", 25); // написание функии 1
		MoveToEx(hDC, center_x + kx, center_y - func1(a) * ky, NULL);

		for (x = a; x <= b; x += 0.001) // рисование f1
			LineTo(hDC, center_x + x * kx, center_y - func1(x) * ky);

		SelectObject(hDC, Pen_fun2);
		TextOutA(hDC, center_x + b * kx + 10, center_y - func2(b) * ky + ky / 1.5 - 15, "y = x + sin(x)", 15); // написание функии 2
		MoveToEx(hDC, center_x + kx, center_y - func2(a) * ky + ky / 1.8, NULL); // 1.8 для другого масштаба

		for (x = a; x <= b; x += 0.001) // рисование f2
			LineTo(hDC, center_x + x * kx, center_y - func2(x) * ky + ky / 1.8);

		int choice = _getch();
		if (choice == ESC)
		{
			system("cls");
			exit = true;
		}
		else
			system("cls");
	} while (!exit);
}

