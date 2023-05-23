#include "Task4.h" 	//���������� �������

/*----------------------------------------*/
/* ������ ������ Suit                     */
/*----------------------------------------*/
Suit::Suit(int InitX, int InitY, int InitD1, int InitD2) : VirtualPoint(InitX, InitY)
{
	d1 = InitD1;
	d2 = InitD2;
	Visible = false;
}

Suit::~Suit(void)
{
};

void Suit::Show(void) {
	Visible = true;
	int halfWidth = d1 / 2,
		halfHeight = d2 / 2;
	// ����

	SelectObject(hdc, RedPen);

	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, halfWidth + X, halfHeight + Y);

	/*MoveToEx(hdc, halfWidth + X, Y + halfHeight, NULL);*/
	LineTo(hdc, X, d2 + Y);

	/*MoveToEx(hdc, X - halfWidth, Y + halfHeight, NULL);*/
	LineTo(hdc, X - halfWidth, Y + halfHeight);

	/*MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);*/
	LineTo(hdc, X, Y);
}

void Suit::Hide(void) {
	Visible = false;
	int halfWidth = d1 / 2,
		halfHeight = d2 / 2;
	// ����

	SelectObject(hdc, WhitePen);

	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, halfWidth + X, halfHeight + Y);

	/*MoveToEx(hdc, halfWidth + X, Y + halfHeight, NULL);*/
	LineTo(hdc, X, d2 + Y);

	/*MoveToEx(hdc, X - halfWidth, Y + halfHeight, NULL);*/
	LineTo(hdc, X - halfWidth, Y + halfHeight);

	/*MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);*/
	LineTo(hdc, X, Y);
}

int Suit::GetD1() {
	return d1;
}

int Suit::GetD2() {
	return d2;
}

/*---------------------------------------*/
/*        ������ ������ Stone            */
/*---------------------------------------*/
Stone::Stone(int InitX, int InitY, int InitRadius) : VirtualPoint(InitX, InitY)
{
	radius = InitRadius;
	Visible = false;
}

//����������
Stone::~Stone(void)
{
};

void Stone::Show() {
	Visible = true;

	SelectObject(hdc, BlackPen);
	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}

void Stone::Hide(void) {
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);

	MoveToEx(hdc, X, Y, NULL);

	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}

int Stone::GetRadius() {
	return radius;
}

/*----------------------------------------*/
/*    ������ ������ AbstractFigure        */
/*----------------------------------------*/
AbstractFigure::AbstractFigure(int InitX, int InitY, int initWidth, int initHeight)
{
	X = InitX;
	Y = InitY;
	width = initWidth;
	height = initHeight;
	Visible = false;
}

//�������� X ���������� ������
int AbstractFigure::GetX(void)
{
	return X;
};

//�������� Y ���������� ������
int AbstractFigure::GetY(void)
{
	return Y;
};

void AbstractFigure::SetX(int newX) {
	X = newX;
}

void AbstractFigure::SetY(int newY) {
	Y = newY;
}

//������ ��� ���������� ������
bool AbstractFigure::IsVisible(void)
{
	return Visible;
};

//����������� ������
void AbstractFigure::MoveTo(int NewX, int NewY)
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};

// ���������� ������
void AbstractFigure::Drag(int Step)
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

bool AbstractFigure::IsHit(AbstractFigure* figure)
{
	int objectX = figure->GetX(), objectY = figure->GetY();
	bool hitX = X + width >= objectX && X <= objectX + figure->GetWidth();
	bool hitY = Y + height >= objectY && Y <= objectY + figure->GetHeight();

	return hitX && hitY;
}

bool AbstractFigure::IsHit(Suit* suit)
{
	int objectX = suit->GetX(), objectY = suit->GetY();
	int left = objectX - (suit->GetD1() / 2), right = (suit->GetD1() / 2) + objectX;
	int bottom = objectY + suit->GetD2();

	bool hitX = X + width >= left && X <= right;
	bool hitY = Y + height >= objectY && Y <= bottom;

	return hitX && hitY;
	return true;
}

bool AbstractFigure::IsHit(Stone* stone)
{
	int stoneX = stone->GetX(), stoneY = stone->GetY();
	int stoneRadius = stone->GetRadius();
	bool hitX = X + width >= stoneX - stoneRadius && X <= stoneX + stoneRadius;
	bool hitY = Y + height >= stoneY - stoneRadius && Y <= stoneY + stoneRadius;

	return hitX && hitY;
}


/*----------------------------------------*/
/* ������ ������ Figure�rhomb7            */
/*----------------------------------------*/
Figure�rhomb7::Figure�rhomb7(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

Figure�rhomb7::~Figure�rhomb7(void)
{
};

void Figure�rhomb7::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

	// ����� 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);

	// ����

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void Figure�rhomb7::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

/*----------------------------------------*/
/* ������ ������ Figure�rhomb8            */
/*----------------------------------------*/
Figure�rhomb8::Figure�rhomb8(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

Figure�rhomb8::~Figure�rhomb8(void)
{
};

void Figure�rhomb8::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 20;

	// 8
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2 + numberRadius * 2, NULL);
	Ellipse(hdc, shiftedX, shiftedY + numberRadius * 2, shiftedX + numberRadius * 2, shiftedY + numberRadius * 4);

	// ����

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void Figure�rhomb8::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}


/*----------------------------------------*/
/* ������ ������ Figure�rhomb8WithHole    */
/*----------------------------------------*/
Figure�rhomb8WithHole::Figure�rhomb8WithHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

Figure�rhomb8WithHole::~Figure�rhomb8WithHole(void)
{
};

void Figure�rhomb8WithHole::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 20;

	// ����� 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2 + numberRadius * 2, NULL);
	Ellipse(hdc, shiftedX, shiftedY + numberRadius * 2, shiftedX + numberRadius * 2, shiftedY + numberRadius * 4);

	// ����

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);


	SelectObject(hdc, BlackPen);
	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
}

void Figure�rhomb8WithHole::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

/*----------------------------------------*/
/* ������ ������ Figure�rhomb10           */
/*----------------------------------------*/
Figure�rhomb10::Figure�rhomb10(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

Figure�rhomb10::~Figure�rhomb10(void)
{
};

void Figure�rhomb10::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 30;

	// ����� 10
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth / 2 + X, Y + tenthHeight * 2);

	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);

	// ����

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void Figure�rhomb10::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

/*----------------------------------------*/
/* ������ ������ Figure�rhomb1           */
/*----------------------------------------*/
Figure�rhomb1::Figure�rhomb1(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

Figure�rhomb1 ::~Figure�rhomb1(void)
{
};

void Figure�rhomb1::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 30;

	// ����� 10
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth / 2 + X, Y + tenthHeight * 2);

	// ����

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void Figure�rhomb1::Hide(void)
{
	Visible = false;

	// �������������
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}