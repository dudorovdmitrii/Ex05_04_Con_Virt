#include "Task3.h" 	//îáúÿâëåíèå êëàññîâ

/*----------------------------------------*/
/*        ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureBlank       */
/*----------------------------------------*/
FigureBlank::FigureBlank(int InitX, int InitY, int initWidth, int initHeight) : VirtualFigure(InitX, InitY, initWidth, initHeight)
{
}

FigureBlank::~FigureBlank(void)
{
};

void FigureBlank::Show(void) {
	Visible = true;
	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10);


	// ïðÿìîóãîëüíèê
	SelectObject(hdc, BlackPen);

	MoveToEx(hdc, X, Y, NULL);
	Rectangle(hdc, X, Y, X + width, Y + height);
}

bool FigureBlank::IsHit(Stone* stone)
{
	int stoneX = stone->GetX(), stoneY = stone->GetY();
	int stoneRadius = stone->GetRadius();
	bool hitX = X + width >= stoneX - stoneRadius && X <= stoneX + stoneRadius;
	bool hitY = Y + height >= stoneY - stoneRadius && Y <= stoneY + stoneRadius;

	return hitX && hitY;
}

bool FigureBlank::IsHit(Suit* suit)
{
	int objectX = suit->GetX(), objectY = suit->GetY();
	int left = objectX - (suit->GetD1() / 2), right = (suit->GetD1() / 2) + objectX;
	int bottom = objectY + suit->GetD2();

	bool hitX = X + width >= left && X <= right;
	bool hitY = Y + height >= objectY && Y <= bottom;

	return hitX && hitY;
	return true;
}

bool FigureBlank::IsHit(Number* number)
{
	int objectX = number->GetX(), objectY = number->GetY();
	int left = objectX, right = objectX + number->GetTenthWidth() * 2;
	int bottom = objectY + number->GetTenthHeight() * 2;
	bool hitX = X + width >= left && X <= right;
	bool hitY = Y + height >= objectY && Y <= bottom;

	return hitX && hitY;
}

void FigureBlank::SetX(int newX) {
	X = newX;
}

void FigureBlank::SetY(int newY) {
	Y = newY;
}

/*----------------------------------------*/
/*        ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureWithNumber  */
/*----------------------------------------*/
FigureWithNumber::FigureWithNumber(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureWithNumber::~FigureWithNumber(void)
{
};

void FigureWithNumber::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10);

	// öèôðà 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
}

/*----------------------------------------*/
/*        ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureWithSuit    */
/*----------------------------------------*/
FigureWithSuit::FigureWithSuit(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureWithSuit::~FigureWithSuit(void)
{
};

void FigureWithSuit::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10);
	// ðîìá

	SelectObject(hdc, RedPen);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, fourthWidth + X, fourthHeight * 2 + Y);

	MoveToEx(hdc, halfWidth + X, Y + fourthHeight * 3, NULL);
	LineTo(hdc, X + 3 * fourthWidth, fourthHeight * 2 + Y);
}

/*----------------------------------------*/
/*        ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureWithHole    */
/*----------------------------------------*/
FigureWithHole::FigureWithHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureWithHole::~FigureWithHole(void)
{
};

void FigureWithHole::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

	SelectObject(hdc, BlackPen);
	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
}

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureWithNumberAndSuit  */
/*----------------------------------------*/
FigureWithNumberAndSuit::FigureWithNumberAndSuit(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureWithNumberAndSuit::~FigureWithNumberAndSuit(void)
{
};

void FigureWithNumberAndSuit::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10);

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

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureWithNumberAndHole  */
/*----------------------------------------*/
FigureWithNumberAndHole::FigureWithNumberAndHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureWithNumberAndHole::~FigureWithNumberAndHole(void)
{
};

void FigureWithNumberAndHole::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

	// öèôðà 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, tenthWidth / 2 + X, Y + tenthHeight / 2, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y + tenthHeight / 2);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);

	SelectObject(hdc, BlackPen);
	Ellipse(hdc, X + radius, Y + radius, X + radius * 2, Y + radius * 2);
}

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureWithSuitAndHole    */
/*----------------------------------------*/
FigureWithSuitAndHole::FigureWithSuitAndHole(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureWithSuitAndHole::~FigureWithSuitAndHole(void)
{
};

void FigureWithSuitAndHole::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

	// ðîìá

	SelectObject(hdc, RedPen);

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

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ FigureComplete           */
/*----------------------------------------*/
FigureComplete::FigureComplete(int InitX, int InitY, int initWidth, int initHeight) : FigureBlank(InitX, InitY, initWidth, initHeight)
{
}

FigureComplete::~FigureComplete(void)
{
};

void FigureComplete::Show(void) {
	FigureBlank::Show();

	int halfWidth = (width / 2),
		fourthHeight = (height / 4),
		fourthWidth = (width / 4),
		tenthWidth = (width / 10),
		tenthHeight = (height / 10),
		radius = 50;

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

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ Suit                     */
/*----------------------------------------*/
Suit::Suit(int InitX, int InitY, int InitD1, int InitD2) : VirtualPoint(InitX, InitY)
{
	d1 = InitD1;
	d2 = InitD2;
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

/*----------------------------------------*/
/* ÌÅÒÎÄÛ ÊËÀÑÑÀ Number                   */
/*----------------------------------------*/
Number::Number(int InitX, int InitY, int InitTenthWidth, int InitTenthHeight) : VirtualPoint(InitX, InitY)
{
	tenthWidth = InitTenthWidth;
	tenthHeight = InitTenthHeight;
}

Number::~Number(void)
{
};

void Number::Show(void) {
	Visible = true;
	// öèôðà 7
	SelectObject(hdc, RedPen);
	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
}

void Number::Hide(void) {
	Visible = false;
	// öèôðà 7
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	LineTo(hdc, tenthWidth * 2 + X, Y);
	LineTo(hdc, tenthWidth + X, Y + tenthHeight * 2);
}

int Number::GetTenthWidth() {
	return tenthWidth;
}

int Number::GetTenthHeight() {
	return tenthHeight;
}