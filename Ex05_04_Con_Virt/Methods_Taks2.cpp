#include "Task2.h"

/*---------------------------------------*/
/*        МЕТОДЫ КЛАССА HittableFigure   */
/*---------------------------------------*/


HittableFigure::HittableFigure(int InitX, int InitY, int initWidth, int initHeight) : VirtualFigure(InitX, InitY, initWidth, initHeight)
{
	countHoles = 0;

	for (int i = 0; i < enemyStoneCount; i++) {
		holes[i] = nullptr;
	}
}

HittableFigure::~HittableFigure(void)
{
};

bool HittableFigure::IsHit(EnemyStone* stone)
{
	int stoneX = stone->GetX(), stoneY = stone->GetY();
	int stoneRadius = stone->GetRadius();
	bool hitX = X + width >= stoneX - stoneRadius && X <= stoneX + stoneRadius;
	bool hitY = Y + height >= stoneY - stoneRadius && Y <= stoneY + stoneRadius;

	return hitX && hitY;
}

bool HittableFigure::IsHit(Stone* stone)
{
	int stoneX = stone->GetX(), stoneY = stone->GetY();
	int stoneRadius = stone->GetRadius();
	bool hitX = X + width >= stoneX - stoneRadius && X <= stoneX + stoneRadius;
	bool hitY = Y + height >= stoneY - stoneRadius && Y <= stoneY + stoneRadius;

	return hitX && hitY;
}


void HittableFigure::Heal()
{
	if (countHoles > 0) {
		for (int i = 0; i < countHoles; i++) {
			if (holes[i]->IsVisible()) {
				holes[i]->ToggleOnFigure();
				holes[i]->Hide(X, Y);
				Show();
				return;
			}
		}
	}
}

void HittableFigure::AttachHole(EnemyStone* stone)
{
	stone->Hide();

	int stoneRadius = stone->GetRadius();
	int newX = rand() % width, newY = rand() % height;

	if (newX + stoneRadius > width) {
		newX -= stoneRadius;
	}
	if (newY + stoneRadius > height) {
		newY -= stoneRadius;
	}
	if (newX - stoneRadius < 0) {
		newX += stoneRadius;
	}
	if (newY - stoneRadius < 0) {
		newY += stoneRadius;
	}

	holes[countHoles++] = stone;
	stone->ToggleOnFigure(newX, newY);
	stone->Show(X, Y);
	Show();
}

int HittableFigure::GetWidth() {
	return width;
}

int HittableFigure::GetHeight() {
	return height;
}

void HittableFigure::Show(void) {
	VirtualFigure::Show();

	if (countHoles > 0) {
		for (int i = 0; i < countHoles; i++) {
			if (holes[i] && holes[i]->IsVisible()) {
				holes[i]->Show(X, Y);
			}
		}
	}
}

/*---------------------------------------*/
/*        МЕТОДЫ КЛАССА Stone            */
/*---------------------------------------*/
Stone::Stone(int InitX, int InitY, int InitRadius) : VirtualPoint(InitX, InitY)
{
	radius = InitRadius;
}

//деструктор
Stone::~Stone(void)
{
};


void Stone::Show() {
	Visible = true;

	// прямоугольник
	SelectObject(hdc, BlackPen);
	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}


void Stone::Hide(void) {
	Visible = false;

	// прямоугольник
	SelectObject(hdc, WhitePen);

	MoveToEx(hdc, X, Y, NULL);

	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}

int Stone::GetRadius() {
	return radius;
}


/*---------------------------------------*/
/*        МЕТОДЫ КЛАССА EnemyStone       */
/*---------------------------------------*/

EnemyStone::EnemyStone(int InitX, int InitY, int InitRadius) : Stone(InitX, InitY, InitRadius)
{
	onFigure = false;
}

//деструктор
EnemyStone::~EnemyStone(void)
{
};

void EnemyStone::ToggleOnFigure() {
	onFigure = !onFigure;
}

void EnemyStone::ToggleOnFigure(int newX, int newY) {
	// Задаем координаты относительно фигуры
	X = newX;
	Y = newY;

	onFigure = !onFigure;
}

bool EnemyStone::IsOnFigure() {
	return onFigure;
}


void EnemyStone::Show() {
	Visible = true;

	// прямоугольник
	SelectObject(hdc, RedPen);
	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}

void EnemyStone::Show(int shiftX, int shiftY) {
	Visible = true;
	int shiftedX = X + shiftX, shiftedY = Y + shiftY;

	// прямоугольник
	SelectObject(hdc, RedPen);
	Ellipse(hdc, shiftedX - radius, shiftedY + radius, shiftedX + radius, shiftedY - radius);
}

void EnemyStone::Hide(int shiftX, int shiftY) {
	Visible = false;
	int shiftedX = X + shiftX, shiftedY = Y + shiftY;

	// прямоугольник
	SelectObject(hdc, WhitePen);
	MoveToEx(hdc, X, Y, NULL);
	Ellipse(hdc, shiftedX - radius, shiftedY + radius, shiftedX + radius, shiftedY - radius);
}

void EnemyStone::Hide(void) {
	Visible = false;

	// прямоугольник
	SelectObject(hdc, WhitePen);

	MoveToEx(hdc, X, Y, NULL);

	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}

/*---------------------------------------*/
/*        МЕТОДЫ КЛАССА FriendStone      */
/*---------------------------------------*/

FriendStone::FriendStone(int InitX, int InitY, int InitRadius) : Stone(InitX, InitY, InitRadius)
{
}

//деструктор
FriendStone::~FriendStone(void)
{
};


void FriendStone::Show() {
	Visible = true;

	// прямоугольник
	SelectObject(hdc, GreenPen);
	Ellipse(hdc, X - radius, Y + radius, X + radius, Y - radius);
}