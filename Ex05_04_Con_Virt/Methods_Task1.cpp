#include "Task1.h"	//объявление классов

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Location          */
/*----------------------------------------*/
//конструктор
Location::Location(int InitX, int InitY)
{
	X = InitX;
	Y = InitY;
};

  //деструктор
Location::~Location(void) 
{
};

  //получить X координату точки
int Location::GetX(void)
{
	return X;
};

  //получить Y координату точки
int Location::GetY(void)
{
	return Y;
};


/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА Point             */
/*----------------------------------------*/

//конструктор
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;
}

 //деструктор
Point::~Point(void)
{
}

 //показать ТОЧКУ
void Point::Show(void)
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//рисуем красным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 точки для удобства
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}

 //скрыть ТОЧКУ
void Point::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X    , Y    , RGB(0, 0, 255));//рисуем синим цветом или фона
	SetPixel(hdc, X + 1, Y    , RGB(0, 0, 255));
	SetPixel(hdc, X    , Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}

 //узнать про светимость ТОЧКИ
bool Point::IsVisible(void) 
{ 
	return Visible; 
};

//переместить ТОЧКУ
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//сделать точку невидимой
	X = NewX;	//поменять координаты ТОЧКИ
	Y = NewY;
	Show();		//показать точку на новом месте
};

// буксировка фигуры
void Point::Drag(int Step)
{
	int FigX, FigY;
	// новые координаты фигуры
	FigX = GetX();
	// получаем начальные координаты
	FigY = GetY();
	// получаем начальные координаты
	// бесконечный цикл буксировки фигуры
	while (1)
	{
		if (KEY_DOWN(VK_ESCAPE)) // цифра 27 конец работы 
		{
			break;
		}

		// направаление движения объекта
		if (KEY_DOWN(VK_LEFT))
			// 37 стрелка влево
		{
			FigX -= Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
		if (KEY_DOWN(VK_RIGHT))
			// 39 стрелка вправо
		{
			FigX += Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
		if (KEY_DOWN(VK_DOWN))
			// 40 стрелка вниз
		{
			FigY += Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
		if (KEY_DOWN(VK_UP))
			// 38 стрелка вверх
		{
			FigY -= Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
	}
}

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА VirtualPoint      */
/*----------------------------------------*/

//конструктор
VirtualPoint::VirtualPoint(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;
}

//деструктор
VirtualPoint::~VirtualPoint(void)
{
}

//показать ТОЧКУ
void VirtualPoint::Show(void)
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//рисуем красным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 точки для удобства
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}

//скрыть ТОЧКУ
void VirtualPoint::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X, Y, RGB(0, 0, 255));//рисуем синим цветом или фона
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}

//узнать про светимость ТОЧКИ
bool VirtualPoint::IsVisible(void)
{
	return Visible;
};

//переместить ТОЧКУ
void VirtualPoint::MoveTo(int NewX, int NewY)
{
	Hide();		//сделать точку невидимой
	X = NewX;	//поменять координаты ТОЧКИ
	Y = NewY;
	Show();		//показать точку на новом месте
};

// буксировка фигуры
void VirtualPoint::Drag(int Step)
{
	int FigX, FigY;
	// новые координаты фигуры
	FigX = GetX();
	// получаем начальные координаты
	FigY = GetY();
	// получаем начальные координаты
	// направаление движения объекта

	if (KEY_DOWN(VK_LEFT))
		// 37 стрелка влево
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_RIGHT))
		// 39 стрелка вправо
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_DOWN))
		// 40 стрелка вниз
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_UP))
		// 38 стрелка вверх
	{
		FigY -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
}

/*---------------------------------------*/
/*        МЕТОДЫ КЛАССА BaseFigure       */
/*---------------------------------------*/
BaseFigure::BaseFigure(int InitX, int InitY, int initWidth, int initHeight) : Point(InitX, InitY)
{
	width = initWidth;
	height = initHeight;
}

//деструктор
BaseFigure::~BaseFigure(void)
{
};

void BaseFigure::Show(void) {
	Visible = true;
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10);


	// прямоугольник
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// ромб

	SelectObject(hdc, RedPen);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	// цифра 7
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
}

void BaseFigure::Hide(void)
{
	Visible = false;

	// прямоугольник
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

//переместить ТОЧКУ
void BaseFigure::MoveTo(int NewX, int NewY)
{
	Hide();		//сделать точку невидимой
	X = NewX;	//поменять координаты ТОЧКИ
	Y = NewY;
	Show();		//показать точку на новом месте
};

// буксировка фигуры
void BaseFigure::Drag(int Step)
{
	int FigX, FigY;
	// новые координаты фигуры
	FigX = GetX();
	// получаем начальные координаты
	FigY = GetY();
	// получаем начальные координаты

	// направаление движения объекта
	if (KEY_DOWN(VK_LEFT))
		// 37 стрелка влево
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_RIGHT))
		// 39 стрелка вправо
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_DOWN))
		// 40 стрелка вниз
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_UP))
		// 38 стрелка вверх
	{
		FigY -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
}

/*---------------------------------------*/
/*        МЕТОДЫ КЛАССА VirtualFigure */
/*---------------------------------------*/
VirtualFigure::VirtualFigure(int InitX, int InitY, int initWidth, int initHeight) : VirtualPoint(InitX, InitY)
{
	width = initWidth;
	height = initHeight;
}

//деструктор
VirtualFigure::~VirtualFigure(void)
{
};


void VirtualFigure::Show(void) {
	Visible = true;
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10);


	// прямоугольник
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// ромб

	SelectObject(hdc, RedPen);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	// цифра 7
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
 }

void VirtualFigure::Hide(void)
{
	Visible = false;

	// прямоугольник
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}