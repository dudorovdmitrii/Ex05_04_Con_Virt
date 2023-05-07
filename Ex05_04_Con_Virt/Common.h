#pragma once
#include <windows.h>
#include <string>
#include<iostream>
#include <time.h>
#include "GetConlWin.h"		//указатель на консольное окно
using namespace std;

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

void task1(int initX, int initY, int initWidth, int initHeight, int dragValue);
void task2(int initX, int initY, int initWidth, int initHeight, int dragValue);

extern HPEN WhitePen;
extern HPEN BlackPen;
extern HPEN RedPen;
extern HPEN GreenPen;

extern HDC hdc;
extern HWND hwnd;
