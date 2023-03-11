#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"

#define UP 72
#define DOWN 80
#define ESC 27

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void menu_start();
void gotoxy(short a, short b);
void print_menu(int active_elem);
int cursorVisible(HANDLE hStdOut);


void menu_start() {
	HDC hDC = GetDC(GetConsoleWindow());
	system("cls");
	bool exit = false;
	int active_elem = 0;
	do
	{
		print_menu(active_elem);
		int choice = _getch();
		switch (choice)
		{
		case UP://�����
			if (active_elem == 0)
			{
				active_elem = 5;
				break;
			}
			else
			{
				active_elem--;
				break;
			}
		case DOWN://����
			if (active_elem == 5)
			{
				active_elem = 0;
				break;
			}
			else
			{
				active_elem++;
				break;
			}
		case ESC: //exit
			exit = true;
			break;
		}
	} while (!exit);
}

void gotoxy(short a, short b)
{
	COORD coordinates;
	coordinates.X = a;
	coordinates.Y = b;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void print_menu(int active_elem) {
	cursorVisible(handle);
	string menu_text[] = { "������ ������� � ���������� �������", "������ ������������� ���������",
	"����� ����� ���������", "���������� �� ������", "����������� ��������", "���������� � ������" };
	int x = 12;
	int y = 6;
	gotoxy(x, y);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "\t\t\t\t\t" << "�������� - ����������� ������" << "\n";
	y += 2;
	for (int i = 0; i < size(menu_text); i++)
	{
		y += 2;
		gotoxy(x, y);
		if (active_elem == i)
		{
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "\t\t\t\t\t" << menu_text[i] << "\n";
		}
		else
		{
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			cout << "\t\t\t\t\t" << menu_text[i] << "\n";
		}
	}
}

int cursorVisible(HANDLE hStdOut) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	return 0;
}