#include "Table.h"
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"

#define a 1
#define b 2
#define n 18
#define ESC 27

HANDLE handle_text = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void MaxMin(double* f, double* maxF, double* minF);

void table()
{
    HDC hDC = GetDC(GetConsoleWindow());
    double dx, x[19], f1[18], f2[18];
    dx = fabs(b - a) / (n - 1);
    x[0] = a;
    for (int i = 0; i < n; i++) { // считаем значение функций
        f1[i] = exp((-1) * x[i]) * log(pow(x[i] + 1, 0.5));
        f2[i] = x[i] + sin(x[i]);
        x[i + 1] = x[i] + dx;
    }
    double maxF1, minF1, maxF2, minF2;
    MaxMin(f1, &maxF1, &minF1);
    MaxMin(f2, &maxF2, &minF2);
    bool exit = false;
    do // выводим табличку
    {
        system("cls");
        SetConsoleTextAttribute(handle_text, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        int x_cord = 27; // кооридинаты откуда начинается табличка
        int y_cord = 3;
        gotoxy(x_cord, y_cord);
        cout << "______________________________________________________________";
        y_cord += 1;
        gotoxy(x_cord, y_cord);
        printf("|\tI\t|\tX\t|\tF1\t|\tF2\t|");
        y_cord += 1;
        gotoxy(x_cord, y_cord);
        cout <<"|____________|_______________|_______________|_______________|";
        y_cord += 1;
        for (int i = 0; i < n; i++) {
            gotoxy(x_cord, y_cord);
            y_cord += 1;
            printf("|\t%d\t|\t%.3f\t|\t", i, x[i]);

            if (f1[i] == maxF1) // выделение цветом max и min
            {
                SetConsoleTextAttribute(handle_text, FOREGROUND_GREEN);
                printf("%.3f", f1[i]);
                SetConsoleTextAttribute(handle_text, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else
            {
                if (f1[i] == minF1)
                {
                    SetConsoleTextAttribute(handle_text, FOREGROUND_RED);
                    printf("%.3f", f1[i]);
                    SetConsoleTextAttribute(handle_text, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                }
                else
                    printf("%.3f", f1[i]);
            }
            printf("\t|\t");


            if (f2[i] == maxF2) // выделение цветом max и min
            {
                SetConsoleTextAttribute(handle_text, FOREGROUND_GREEN);
                printf("%.3f", f2[i]);
                SetConsoleTextAttribute(handle_text, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            }
            else
            {
                if (f2[i] == minF2)
                {
                    SetConsoleTextAttribute(handle_text, FOREGROUND_RED);
                    printf("%.3f", f2[i]);
                    SetConsoleTextAttribute(handle_text, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                }
                else
                    printf("%.3f", f2[i]);
            }
            printf("\t|");
        }
        gotoxy(x_cord, y_cord);
        printf("|____________|_______________|_______________|_______________|");
        int choice = _getch();
        if (choice == ESC)
        {
            system("cls");
            exit = true;
        }
    } while (!exit);
}

void MaxMin(double* f, double* maxF, double* minF) {
    double max = -1000;
    double min = 1000;
    for (int i = 0; i < n; i++)
    {
        if (f[i] > max) {
            *maxF = f[i];
            max = f[i];
        }
        if (f[i] < min)
        {
            *minF = f[i];
            min = f[i];
        }
    }
}
