#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define _WIN32_WINNT 0x0A00

using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

//void View() {
//	HDC hDC = GetDC(GetConsoleWindow());
//	char TextExit[1024];
//	do
//	{
//		sprintf(TextExit, "Для выходы нажмите ESC");
//		TextOutA(hDC, 50, 200, TextExit, strlen(TextExit) + 1);
//		Sleep(20);
//	} while (GetKeyState(VK_ESCAPE) >= 0);
//}
bool check(char choice);
void ex_One();
int main()
{
	system("chcp 1251");
	system("cls");
	HDC hDC = GetDC(GetConsoleWindow());
	char choice;
	bool exit = false;
	//HPEN Pen = CreatePen(PS_SOLID, 0, RGB(255, 148, 148));
	//SelectObject(hDC, Pen);
	do
	{
		system("cls");
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		cout << "\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t  Расчетно-графическая работа\n";
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
		cout << "\t\t\t\t\t ___________________________________________\n";
		cout << "\t\t\t\t\t|                                           |\n";
		cout << "\t\t\t\t\t|    1. Расчет функций и построение графика |\n";
		cout << "\t\t\t\t\t|    2. Расчет определенного интеграла      |\n";
		cout << "\t\t\t\t\t|    3. Поиск корня уравнения               |\n";
		cout << "\t\t\t\t\t|    4. Информация об авторе                |\n";
		cout << "\t\t\t\t\t|    5. Графическая заставка                |\n";
		cout << "\t\t\t\t\t|    6. Информация о авторе                 |\n";
		cout << "\t\t\t\t\t|___________________________________________|\n\n";
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "\t\t\t\t\t Ваш выбор: ";
		cin >> choice;
		if (check(choice) == false)
		{
			cout << "\n\t\t\t\t\tВы ввели неверное число!";
			Sleep(500);
			continue;
		}
		switch (choice) {
		case '1': {ex_One(); break; }
		case '2': { break; }
		case '3': { break; }
		case '4': { break; }
		case '5': { break; }
		case '6': { exit = true; break; }
		}
		
		if (exit == true)
			break;

	} while (true);
}

void ex_One() {
	do
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t\t  Построение графиков функции\n";


	} while (true);
}

bool check(char choice) {
	return choice > '0' && choice <= '6';
}
