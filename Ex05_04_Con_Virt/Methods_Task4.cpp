#include "Task4.h" 	//îáúÿâëåíèå êëàññîâ

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ Suit                     */
/*----------------------------------------*/
Suit::Suit(int InitX, int InitY, int InitD1, int InitD2)
{
	X = InitX;
	Y = InitY;
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
	// ðîìá

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
	// ðîìá

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

int Suit::GetX(void)
{
	return X;
};

//ïîëó÷èòü Y êîîðäèíàòó ôèãóðû
int Suit::GetY(void)
{
	return Y;
};

bool Suit::IsVisible(void)
{
	return Visible;
};

/*---------------------------------------*/
/*        ÌÅÒÎÄÛ ÊËÀÑÑÀ Stone            */
/*---------------------------------------*/
Stone::Stone(int InitX, int InitY, int InitRadius)
{
	X = InitX;
	Y = InitY;
	radius = InitRadius;
	Visible = false;
}

//äåñòðóêòîð
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

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);

	MoveToEx(hdc, X, Y, NULL);

	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}

int Stone::GetRadius() {
	return radius;
}

int Stone::GetX(void)
{
	return X;
};

//ïîëó÷èòü Y êîîðäèíàòó ôèãóðû
int Stone::GetY(void)
{
	return Y;
};

bool Stone::IsVisible(void)
{
	return Visible;
};

/*----------------------------------------*/
/*    ÌÅÒÎÄÛ ÊËÀÑÑÀ AbstractFigure        */
/*----------------------------------------*/
AbstractFigure::AbstractFigure(int InitX, int InitY, int initWidth, int initHeight)
{
	X = InitX;
	Y = InitY;
	width = initWidth;
	height = initHeight;
	Visible = false;
}

//ïîëó÷èòü X êîîðäèíàòó ôèãóðû
int AbstractFigure::GetX(void)
{
	return X;
};

//ïîëó÷èòü Y êîîðäèíàòó ôèãóðû
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

//óçíàòü ïðî ñâåòèìîñòü ôèãóðû
bool AbstractFigure::IsVisible(void)
{
	return Visible;
};

//ïåðåìåñòèòü ôèãóðó
void AbstractFigure::MoveTo(int NewX, int NewY)
{
	Hide();		//ñäåëàòü òî÷êó íåâèäèìîé
	X = NewX;	//ïîìåíÿòü êîîðäèíàòû ÒÎ×ÊÈ
	Y = NewY;
	Show();		//ïîêàçàòü òî÷êó íà íîâîì ìåñòå
};

// áóêñèðîâêà ôèãóðû
void AbstractFigure::Drag(int Step)
{
	int FigX, FigY;
	// íîâûå êîîðäèíàòû ôèãóðû
	FigX = GetX();
	// ïîëó÷àåì íà÷àëüíûå êîîðäèíàòû
	FigY = GetY();
	// ïîëó÷àåì íà÷àëüíûå êîîðäèíàòû

	// íàïðàâàëåíèå äâèæåíèÿ îáúåêòà
	if (KEY_DOWN(VK_LEFT))
		// 37 ñòðåëêà âëåâî
	{
		FigX -= Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_RIGHT))
		// 39 ñòðåëêà âïðàâî
	{
		FigX += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_DOWN))
		// 40 ñòðåëêà âíèç
	{
		FigY += Step;
		MoveTo(FigX, FigY);
		Sleep(100);
	} // if
	if (KEY_DOWN(VK_UP))
		// 38 ñòðåëêà ââåðõ
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

int AbstractFigure::GetWidth() {
	return width;
}

int AbstractFigure::GetHeight() {
	return height;
}

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureÊrhomb7            */
/*----------------------------------------*/
FigureÊrhomb7::FigureÊrhomb7(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureÊrhomb7::~FigureÊrhomb7(void)
{
};

void FigureÊrhomb7::Show(void) {
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

	Visible = true;
	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// öèôðà 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);

	// ðîìá

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void FigureÊrhomb7::Hide(void)
{
	Visible = false;

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureÊrhomb7WithHole           */
/*----------------------------------------*/
FigureÊrhomb7WithHole::FigureÊrhomb7WithHole(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureÊrhomb7WithHole::~FigureÊrhomb7WithHole(void)
{
};

void FigureÊrhomb7WithHole::Show(void) {
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

	Visible = true;
	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// öèôðà 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);

	// ðîìá

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

void FigureÊrhomb7WithHole::Hide(void)
{
	Visible = false;

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}


/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureÊrhomb8            */
/*----------------------------------------*/
FigureÊrhomb8::FigureÊrhomb8(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureÊrhomb8::~FigureÊrhomb8(void)
{
};

void FigureÊrhomb8::Show(void) {
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 20;

	Visible = true;
	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// 8
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2 + numberRadius * 2, NULL);
	Ellipse(hdc, shiftedX, shiftedY + numberRadius * 2, shiftedX + numberRadius * 2, shiftedY + numberRadius * 4);

	// ðîìá

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void FigureÊrhomb8::Hide(void)
{
	Visible = false;

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}


/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureÊrhomb8WithHole    */
/*----------------------------------------*/
FigureÊrhomb8WithHole::FigureÊrhomb8WithHole(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureÊrhomb8WithHole::~FigureÊrhomb8WithHole(void)
{
};

void FigureÊrhomb8WithHole::Show(void) {

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 20;

	Visible = true;
	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// öèôðà 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2 + numberRadius * 2, NULL);
	Ellipse(hdc, shiftedX, shiftedY + numberRadius * 2, shiftedX + numberRadius * 2, shiftedY + numberRadius * 4);

	// ðîìá

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

void FigureÊrhomb8WithHole::Hide(void)
{
	Visible = false;

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureÊrhomb10           */
/*----------------------------------------*/
FigureÊrhomb10::FigureÊrhomb10(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureÊrhomb10::~FigureÊrhomb10(void)
{
};

void FigureÊrhomb10::Show(void) {
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 30;

	Visible = true;
	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// öèôðà 10
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth / 2 + X, Y + tenthHeight * 2);

	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	int shiftedX = tenthWidth / 2 + X + 5, shiftedY = Y + tenthHeight / 2;
	Ellipse(hdc, shiftedX, shiftedY, shiftedX + numberRadius * 2, shiftedY + numberRadius * 2);

	// ðîìá

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void FigureÊrhomb10::Hide(void)
{
	Visible = false;

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureÊrhomb1           */
/*----------------------------------------*/
FigureÊrhomb1::FigureÊrhomb1(int InitX, int InitY, int initWidth, int initHeight) : AbstractFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureÊrhomb1 ::~FigureÊrhomb1(void)
{
};

void FigureÊrhomb1::Show(void) {
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50,
		numberRadius = 30;

	Visible = true;
	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);

	// öèôðà 10
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth / 2 + X, Y + tenthHeight * 2);

	// ðîìá

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

void FigureÊrhomb1::Hide(void)
{
	Visible = false;

	// ïðÿìîóãîëüíèê
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}