#include "Task2.h";

class Suit : public VirtualPoint {
protected:
	int d1;
	int d2;
public:
	Suit(int InitX, int InitY, int d1, int d2);
	~Suit(); //����������

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
	~Number(); //����������

	int GetTenthWidth();
	int GetTenthHeight();
	void Show(void);
	void Hide(void);
};

class FigureBlank : public VirtualFigure
{
public:
	FigureBlank(int InitX, int InitY, int width, int height);
	~FigureBlank(); //����������

	void Show(void);
	bool IsHit(Stone* stone);
	bool IsHit(Suit* suit);
	bool IsHit(Number* number);
	bool IsHit(FigureBlank* figure);

	void SetX(int newX);
	void SetY(int newY);

	int GetHeight();
	int GetWidth();
};

class FigureWithNumber : public FigureBlank
{
public:
	FigureWithNumber(int InitX, int InitY, int width, int height);
	~FigureWithNumber(); //����������

	void Show(void);
};

class FigureWithSuit : public FigureBlank
{
public:
	FigureWithSuit(int InitX, int InitY, int width, int height);
	~FigureWithSuit(); //����������

	void Show(void);
};

class FigureWithHole : public FigureBlank
{
public:
	FigureWithHole(int InitX, int InitY, int width, int height);
	~FigureWithHole(); //����������

	void Show(void);
};

class FigureWithNumberAndSuit : public FigureBlank
{
public:
	FigureWithNumberAndSuit(int InitX, int InitY, int width, int height);
	~FigureWithNumberAndSuit(); //����������

	void Show(void);
};

class FigureWithNumberAndHole : public FigureBlank
{
public:
	FigureWithNumberAndHole(int InitX, int InitY, int width, int height);
	~FigureWithNumberAndHole(); //����������

	void Show(void);
};

class FigureWithSuitAndHole : public FigureBlank
{
public:
	FigureWithSuitAndHole(int InitX, int InitY, int width, int height);
	~FigureWithSuitAndHole(); //����������

	void Show(void);
};

class FigureComplete : public FigureBlank
{
public:
	FigureComplete(int InitX, int InitY, int width, int height);
	~FigureComplete(); //����������

	void Show(void);
};

class Figure�rhomb1 : public FigureBlank
{
public:
	Figure�rhomb1(int InitX, int InitY, int width, int height);
	~Figure�rhomb1(); //����������

	void Show(void);
};

class Figure�rhomb7 : public FigureBlank
{
public:
	Figure�rhomb7(int InitX, int InitY, int width, int height);
	~Figure�rhomb7(); //����������

	void Show(void);
};

class Figure�rhomb10 : public FigureBlank
{
public:
	Figure�rhomb10(int InitX, int InitY, int width, int height);
	~Figure�rhomb10(); //����������

	void Show(void);
};

class Figure�rhomb8 : public FigureBlank
{
public:
	Figure�rhomb8(int InitX, int InitY, int width, int height);
	~Figure�rhomb8(); //����������

	void Show(void);
};

class Figure�rhomb8WithHole : public FigureBlank
{
public:
	Figure�rhomb8WithHole(int InitX, int InitY, int width, int height);
	~Figure�rhomb8WithHole(); //����������

	void Show(void);
};