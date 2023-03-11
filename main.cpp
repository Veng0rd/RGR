#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"

#define _WIN32_WINNT 0x0A00

using namespace std;


int main()
{
	system("chcp 1251");
	system("cls");
	menu_start();
}
