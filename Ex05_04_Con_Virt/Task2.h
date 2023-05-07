#include "Task1.h";

constexpr int enemyStoneCount = 3, friendStoneCount = 1;

class Stone : public VirtualPoint
{
protected:
	int radius; // радиус
public:
	Stone(int InitX, int InitY, int radius);
	~Stone();

	int GetRadius();

	void Show();
	void Hide();
};

class EnemyStone : public Stone
{
protected:
	bool onFigure;
public:
	EnemyStone(int InitX, int InitY, int radius);
	~EnemyStone();

	void Show(int shiftX, int shiftY);
	void Show(void);

	void Hide(int shiftX, int shiftY);
	void Hide(void);

	void ToggleOnFigure(int newX, int newY);
	void ToggleOnFigure(void);

	bool IsOnFigure();
};

class FriendStone : public Stone
{
public:
	FriendStone(int InitX, int InitY, int radius);
	~FriendStone();

	void Show();
};

class HittableFigure : public VirtualFigure
{
protected:
	int countHoles;
	EnemyStone* holes[enemyStoneCount];
public:
	HittableFigure(int InitX, int InitY, int width, int height);
	~HittableFigure(); //деструктор

	int GetWidth();
	int GetHeight();

	void Show(void);

	void AttachHole(EnemyStone* stone);
	void Heal();

	bool IsHit(EnemyStone* stone);
	bool IsHit(Stone* stone);
};

