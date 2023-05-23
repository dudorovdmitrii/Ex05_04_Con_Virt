#include "Common.h";

// Интерфейс препятствия
class Obstacle {
	// Реализация неизвестна
	virtual void Show(void) = 0;
	virtual void Hide(void) = 0;
	virtual bool IsVisible() = 0;

	virtual int GetX() = 0; //получить X координату препятствия
	virtual int GetY() = 0; //получить Y координату препятствия
};

class Suit : public Obstacle {
protected:
	int d1;
	int d2;
	bool Visible;
	int X;
	int Y;
public:
	Suit(int InitX, int InitY, int d1, int d2);
	~Suit(); //деструктор

	int GetD1();
	int GetD2();
	int GetX(); //получить X координату препятствия
	int GetY(); //получить Y координату препятствия

	void Show(void);
	void Hide(void);
	bool IsVisible();
};

class Stone : public Obstacle
{
protected:
	int radius; // радиус
	bool Visible;
	int X;
	int Y;
public:
	Stone(int InitX, int InitY, int radius);
	~Stone();

	int GetRadius();
	int GetX(); //получить X координату препятствия
	int GetY(); //получить Y координату препятствия

	void Show();
	void Hide();
	bool IsVisible();
};

// Абстрактный класс фигуры
class AbstractFigure {
protected:
	int X; //координата X
	int Y; //координата Y
	int width; //ширина
	int height; //длина
	bool Visible;

public:
	AbstractFigure(int InitX, int InitY, int width, int height);

	int GetX(); //получить X координату точки
	int GetY(); //получить Y координату точки
	int GetWidth();
	int GetHeight();
	void SetX(int newX);
	void SetY(int newY);

	bool IsVisible(); //узнать про светимость точки
	void Drag(int Step);
	void MoveTo(int NewX, int NewY);

	bool IsHit(Stone* stone);
	bool IsHit(Suit* suit);
	bool IsHit(AbstractFigure* figure);
	
	// Реализация неизвестна
	virtual void Show() = 0; //показать фигуру ТОЧКА
	virtual void Hide() = 0; //спрятать фигуру ТОЧКА
};

class FigureКrhomb1 : public AbstractFigure
{
public:
	FigureКrhomb1(int InitX, int InitY, int width, int height);
	~FigureКrhomb1(); //деструктор

	void Show(void);
	void Hide(void);
};

class FigureКrhomb7 : public AbstractFigure
{
public:
	FigureКrhomb7(int InitX, int InitY, int width, int height);
	~FigureКrhomb7(); //деструктор

	void Show(void);
	void Hide(void);
};

class FigureКrhomb7WithHole : public AbstractFigure
{
public:
	FigureКrhomb7WithHole(int InitX, int InitY, int width, int height);
	~FigureКrhomb7WithHole(); //деструктор

	void Show(void);
	void Hide(void);
};

class FigureКrhomb8 : public AbstractFigure
{
public:
	FigureКrhomb8(int InitX, int InitY, int width, int height);
	~FigureКrhomb8(); //деструктор

	void Show(void);
	void Hide(void);
};

class FigureКrhomb8WithHole : public AbstractFigure
{
public:
	FigureКrhomb8WithHole(int InitX, int InitY, int width, int height);
	~FigureКrhomb8WithHole(); //деструктор

	void Show(void);
	void Hide(void);
};

class FigureКrhomb10 : public AbstractFigure
{
public:
	FigureКrhomb10(int InitX, int InitY, int width, int height);
	~FigureКrhomb10(); //деструктор

	void Show(void);
	void Hide(void);
};
