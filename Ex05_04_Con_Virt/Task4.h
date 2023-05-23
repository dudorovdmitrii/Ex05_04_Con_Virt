#include "Common.h";

// ��������� �����������
class Obstacle {
	// ���������� ����������
	virtual void Show(void) = 0;
	virtual void Hide(void) = 0;
	virtual bool IsVisible() = 0;
};

class Suit : public Obstacle {
protected:
	int d1;
	int d2;
	bool Visible;
public:
	Suit(int InitX, int InitY, int d1, int d2);
	~Suit(); //����������

	int GetD1();
	int GetD2();
	void Show(void);
	void Hide(void);
};

class Stone : public Obstacle
{
protected:
	int radius; // ������
	bool Visible;
public:
	Stone(int InitX, int InitY, int radius);
	~Stone();

	int GetRadius();

	void Show();
	void Hide();
};

// ����������� ����� ������
class AbstractFigure {
protected:
	int X; //���������� X
	int Y; //���������� Y
	int width; //������
	int height; //�����
	bool Visible;

public:
	AbstractFigure(int InitX, int InitY, int width, int height);

	int GetX(); //�������� X ���������� �����
	int GetY(); //�������� Y ���������� �����
	void SetX(int newX);
	void SetY(int newY);

	bool IsVisible(); //������ ��� ���������� �����
	void Drag(int Step);
	void MoveTo(int NewX, int NewY);

	bool IsHit(Stone* stone);
	bool IsHit(Suit* suit);
	bool IsHit(AbstractFigure* figure);
	
	// ���������� ����������
	virtual void Show() = 0; //�������� ������ �����
	virtual void Hide() = 0; //�������� ������ �����
};

class Figure�rhomb1 : public AbstractFigure
{
public:
	Figure�rhomb1(int InitX, int InitY, int width, int height);
	~Figure�rhomb1(); //����������

	void Show(void);
	void Hide(void);
};

class Figure�rhomb7 : public AbstractFigure
{
public:
	Figure�rhomb7(int InitX, int InitY, int width, int height);
	~Figure�rhomb7(); //����������

	void Show(void);
	void Hide(void);
};

class Figure�rhomb8 : public AbstractFigure
{
public:
	Figure�rhomb8(int InitX, int InitY, int width, int height);
	~Figure�rhomb8(); //����������

	void Show(void);
	void Hide(void);
};

class Figure�rhomb8WithHole : public AbstractFigure
{
public:
	Figure�rhomb8WithHole(int InitX, int InitY, int width, int height);
	~Figure�rhomb8WithHole(); //����������

	void Show(void);
	void Hide(void);
};

class Figure�rhomb10 : public AbstractFigure
{
public:
	Figure�rhomb10(int InitX, int InitY, int width, int height);
	~Figure�rhomb10(); //����������

	void Show(void);
	void Hide(void);
};
