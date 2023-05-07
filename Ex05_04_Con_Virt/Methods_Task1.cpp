#include "Task1.h"	//���������� �������

/*----------------------------------------*/
/*        ������ ������ Location          */
/*----------------------------------------*/
//�����������
Location::Location(int InitX, int InitY)
{
	X = InitX;
	Y = InitY;
};

  //����������
Location::~Location(void) 
{
};

  //�������� X ���������� �����
int Location::GetX(void)
{
	return X;
};

  //�������� Y ���������� �����
int Location::GetY(void)
{
	return Y;
};


/*----------------------------------------*/
/*        ������ ������ Point             */
/*----------------------------------------*/

//�����������
Point::Point(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;
}

 //����������
Point::~Point(void)
{
}

 //�������� �����
void Point::Show(void)
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//������ ������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 ����� ��� ��������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}

 //������ �����
void Point::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X    , Y    , RGB(0, 0, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X + 1, Y    , RGB(0, 0, 255));
	SetPixel(hdc, X    , Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}

 //������ ��� ���������� �����
bool Point::IsVisible(void) 
{ 
	return Visible; 
};

//����������� �����
void Point::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};

// ���������� ������
void Point::Drag(int Step)
{
	int FigX, FigY;
	// ����� ���������� ������
	FigX = GetX();
	// �������� ��������� ����������
	FigY = GetY();
	// �������� ��������� ����������
	// ����������� ���� ���������� ������
	while (1)
	{
		if (KEY_DOWN(VK_ESCAPE)) // ����� 27 ����� ������ 
		{
			break;
		}

		// ������������ �������� �������
		if (KEY_DOWN(VK_LEFT))
			// 37 ������� �����
		{
			FigX -= Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
		if (KEY_DOWN(VK_RIGHT))
			// 39 ������� ������
		{
			FigX += Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
		if (KEY_DOWN(VK_DOWN))
			// 40 ������� ����
		{
			FigY += Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
		if (KEY_DOWN(VK_UP))
			// 38 ������� �����
		{
			FigY -= Step;
			MoveTo(FigX, FigY);
			Sleep(100);
		} // if
	}
}

/*----------------------------------------*/
/*        ������ ������ VirtualPoint      */
/*----------------------------------------*/

//�����������
VirtualPoint::VirtualPoint(int InitX, int InitY) : Location(InitX, InitY)
{
	Visible = false;
}

//����������
VirtualPoint::~VirtualPoint(void)
{
}

//�������� �����
void VirtualPoint::Show(void)
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//������ ������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 ����� ��� ��������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}

//������ �����
void VirtualPoint::Hide(void)
{
	Visible = false;

	SetPixel(hdc, X, Y, RGB(0, 0, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}

//������ ��� ���������� �����
bool VirtualPoint::IsVisible(void)
{
	return Visible;
};

//����������� �����
void VirtualPoint::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};

// ���������� ������
void VirtualPoint::Drag(int Step)
{
	int FigX, FigY;
	// ����� ���������� ������
	FigX = GetX();
	// �������� ��������� ����������
	FigY = GetY();
	// �������� ��������� ����������
	// ������������ �������� �������

	if (KEY_DOWN(VK_LEFT))
		// 37 ������� �����
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_RIGHT))
		// 39 ������� ������
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_DOWN))
		// 40 ������� ����
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_UP))
		// 38 ������� �����
	{
		FigY -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
}

/*---------------------------------------*/
/*        ������ ������ BaseFigure       */
/*---------------------------------------*/
BaseFigure::BaseFigure(int InitX, int InitY, int initWidth, int initHeight) : Point(InitX, InitY)
{
	width = initWidth;
	height = initHeight;
}

//����������
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


	// �������������
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// ����

	SelectObject(hdc, RedPen);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	// ����� 7
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
}

void BaseFigure::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

//����������� �����
void BaseFigure::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};

// ���������� ������
void BaseFigure::Drag(int Step)
{
	int FigX, FigY;
	// ����� ���������� ������
	FigX = GetX();
	// �������� ��������� ����������
	FigY = GetY();
	// �������� ��������� ����������

	// ������������ �������� �������
	if (KEY_DOWN(VK_LEFT))
		// 37 ������� �����
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_RIGHT))
		// 39 ������� ������
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_DOWN))
		// 40 ������� ����
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_UP))
		// 38 ������� �����
	{
		FigY -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
}

/*---------------------------------------*/
/*        ������ ������ VirtualFigure */
/*---------------------------------------*/
VirtualFigure::VirtualFigure(int InitX, int InitY, int initWidth, int initHeight) : VirtualPoint(InitX, InitY)
{
	width = initWidth;
	height = initHeight;
}

//����������
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


	// �������������
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// ����

	SelectObject(hdc, RedPen);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	// ����� 7
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
 }

void VirtualFigure::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}