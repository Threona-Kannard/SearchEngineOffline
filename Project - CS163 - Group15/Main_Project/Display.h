#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Operator.h"
#include <conio.h>
#include <cctype>
#include <ctime>
#include <Windows.h>

using namespace std;

void PrintLogo1(int x, int y);
void SearchBoard(int x, int y);
void Intialize(Operator &MAIN, locale loc);
void PrintResult(Operator MAIN, vector<int> result, locale );
void gotoxy(int x, int y);
void TextColorSet(int x);
//void ControlCursor(int x, int y);

#endif