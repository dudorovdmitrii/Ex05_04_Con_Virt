#include "Common.h"

extern const int stoneCount;

class Location
{
protected:	
	int X;		//координата X
	int Y;		//координата Y

public: 
	Location(int InitX, int InitY); //конструктор
	~Location();                    //деструктор
	int GetX();						//получить X координату точки
	int GetY();						//получить Y координату точки
};

class Point : public Location
{
protected:						
	bool Visible; //светится точка или нет

public:
	Point(int InitX, int InitY); //конструктор класса
	~Point(); //деструктор
	bool IsVisible(); //узнать про светимость точки

	void Drag(int Step);
	void MoveTo(int NewX, int NewY);
	void Show(); //показать фигуру ТОЧКА
	void Hide(); //спрятать фигуру ТОЧКА
};

class VirtualPoint : public Location
{
protected:
	bool Visible; //светится точка или нет

public:
	VirtualPoint(int InitX, int InitY); //конструктор класса
	~VirtualPoint(); //деструктор
	bool IsVisible(); //узнать про светимость точки
	void MoveTo(int NewX, int NewY); //переместить фигуру
	void Drag(int Step);

	virtual void Show(); //показать фигуру ТОЧК
	virtual void Hide(); //спрятать фигуру ТОЧКА
};


class BaseFigure : public Point
{
protected:
	int width; //ширина
	int height; //длина
public:
	BaseFigure(int InitX, int InitY, int width, int height);
	~BaseFigure();

	void MoveTo(int NewX, int NewY); //переместить фигуру
	void Drag(int Step);
	void Show();
	void Hide();
};

class VirtualFigure : public VirtualPoint
{
protected:					
	int width; //ширина
	int height; //длина
public:
	VirtualFigure(int InitX, int InitY, int width, int height);
	~VirtualFigure();

	void Show();
	void Hide();
};