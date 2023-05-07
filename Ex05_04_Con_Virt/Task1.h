#include "Common.h"

extern const int stoneCount;

class Location
{
protected:	
	int X;		//���������� X
	int Y;		//���������� Y

public: 
	Location(int InitX, int InitY); //�����������
	~Location();                    //����������
	int GetX();						//�������� X ���������� �����
	int GetY();						//�������� Y ���������� �����
};

class Point : public Location
{
protected:						
	bool Visible; //�������� ����� ��� ���

public:
	Point(int InitX, int InitY); //����������� ������
	~Point(); //����������
	bool IsVisible(); //������ ��� ���������� �����

	void Drag(int Step);
	void MoveTo(int NewX, int NewY);
	void Show(); //�������� ������ �����
	void Hide(); //�������� ������ �����
};

class VirtualPoint : public Location
{
protected:
	bool Visible; //�������� ����� ��� ���

public:
	VirtualPoint(int InitX, int InitY); //����������� ������
	~VirtualPoint(); //����������
	bool IsVisible(); //������ ��� ���������� �����
	void MoveTo(int NewX, int NewY); //����������� ������
	void Drag(int Step);

	virtual void Show(); //�������� ������ ����
	virtual void Hide(); //�������� ������ �����
};


class BaseFigure : public Point
{
protected:
	int width; //������
	int height; //�����
public:
	BaseFigure(int InitX, int InitY, int width, int height);
	~BaseFigure();

	void MoveTo(int NewX, int NewY); //����������� ������
	void Drag(int Step);
	void Show();
	void Hide();
};

class VirtualFigure : public VirtualPoint
{
protected:					
	int width; //������
	int height; //�����
public:
	VirtualFigure(int InitX, int InitY, int width, int height);
	~VirtualFigure();

	void Show();
	void Hide();
};