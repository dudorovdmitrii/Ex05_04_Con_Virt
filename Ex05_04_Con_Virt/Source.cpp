#include "Common.h";

HDC hdc;	// Объявим контекст устройства
HWND GetConcolWindow(); //указатель на консольное окно теперь в  "GetConlWin.h"

HPEN WhitePen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
HPEN BlackPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
HPEN RedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
HPEN GreenPen = CreatePen(PS_SOLID, 2, RGB(127, 255, 0));
HWND hwnd = GetConcolWindow();

void main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	//если дескриптор существует - можем работать
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			// Изначальные данные фигуры
			int figureInitX = 50;
			int figureInitY = 150;
			int figureInitWidth = 300;
			int figureInitHeight = 400;
			int figureDragValue = 40;

			int taskNumber; // Номер лабораторной работы

			task3(figureInitX, figureInitY, figureInitWidth, figureInitHeight, figureDragValue);

			//while (true) {
			//	// Очистка консоли
			//	MoveToEx(hdc, 0, 0, NULL);
			//	SelectObject(hdc, WhitePen);
			//	Rectangle(hdc, 0, 0, 10000, 10000);
			//	system("CLS");

			//	// Выбор лабораторной работы
			//	cout << "Лабораторная работа (1-4): ";
			//	cin >> taskNumber;

			//	switch (taskNumber)
			//	{
			//	case 1: {
			//		//task1(figureInitX, figureInitY, figureInitWidth, figureInitHeight, figureDragValue);
			//		break;
			//	}
			//	case 2: {
			//		cout << "Такой лабораторной работы нет!";
			//		//task2(figureInitX, figureInitY, figureInitWidth, figureInitHeight, figureDragValue);
			//		break;
			//	}
			//	case 3: {
			//		cout << "Такой лабораторной работы нет!";
			//		task3(figureInitX, figureInitY, figureInitWidth, figureInitHeight, figureDragValue);
			//		break;
			//	}
			//	case 4: {
			//		//task4(figureInitX, figureInitY, figureInitWidth, figureInitHeight, figureDragValue);
			//		break;
			//	}
			//	default: {
			//		cout << "Такой лабораторной работы нет!";
			//		break;
			//	}
			//	}
			//}
		 }
	 }
}