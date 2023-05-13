#include "Task2.h";

class Suit : public VirtualPoint {
protected:
	int d1;
	int d2;
public:
	Suit(int InitX, int InitY, int d1, int d2);
	~Suit(); //деструктор

	int GetD1();
	int GetD2();
	void Show(void);
	void Hide(void);
};

class Number : public VirtualPoint {
protected:
	int tenthWidth;
	int tenthHeight;
public:
	Number(int InitX, int InitY, int tenthWidth, int tenthHeight);
	~Number(); //деструктор

	int GetTenthWidth();
	int GetTenthHeight();
	void Show(void);
	void Hide(void);
};

class FigureBlank : public VirtualFigure
{
public:
	FigureBlank(int InitX, int InitY, int width, int height);
	~FigureBlank(); //деструктор

	void Show(void);
	bool IsHit(Stone* stone);
	bool IsHit(Suit* suit);
	bool IsHit(Number* number);

	void SetX(int newX);
	void SetY(int newY);
};

class FigureWithNumber : public FigureBlank
{
public:
	FigureWithNumber(int InitX, int InitY, int width, int height);
	~FigureWithNumber(); //деструктор

	void Show(void);
};

class FigureWithSuit : public FigureBlank
{
public:
	FigureWithSuit(int InitX, int InitY, int width, int height);
	~FigureWithSuit(); //деструктор

	void Show(void);
};

class FigureWithHole : public FigureBlank
{
public:
	FigureWithHole(int InitX, int InitY, int width, int height);
	~FigureWithHole(); //деструктор

	void Show(void);
};

class FigureWithNumberAndSuit : public FigureBlank
{
public:
	FigureWithNumberAndSuit(int InitX, int InitY, int width, int height);
	~FigureWithNumberAndSuit(); //деструктор

	void Show(void);
};

class FigureWithNumberAndHole : public FigureBlank
{
public:
	FigureWithNumberAndHole(int InitX, int InitY, int width, int height);
	~FigureWithNumberAndHole(); //деструктор

	void Show(void);
};

class FigureWithSuitAndHole : public FigureBlank
{
public:
	FigureWithSuitAndHole(int InitX, int InitY, int width, int height);
	~FigureWithSuitAndHole(); //деструктор

	void Show(void);
};

class FigureComplete : public FigureBlank
{
public:
	FigureComplete(int InitX, int InitY, int width, int height);
	~FigureComplete(); //деструктор

	void Show(void);
};
