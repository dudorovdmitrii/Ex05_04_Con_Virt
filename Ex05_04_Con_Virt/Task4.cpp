#include "Task4.h" 	//���������� �������

void task4(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	AbstractFigure* pointerFigure;

	Suit suit(initX + initWidth * 2, initY + initHeight, initWidth / 2, initHeight / 2);
	suit.Show();

	Stone stone(initX + initWidth * 2, initY, 30);
	stone.Show();

	// ����� � 1
	Figure�rhomb1 figure�rhomb1(initX + initWidth * 3, initY + initHeight + 10, initWidth, initHeight);
	figure�rhomb1.Show();

	// ����� � 7
	Figure�rhomb7 figure�rhomb7(initX, initY, initWidth, initHeight);
	pointerFigure = &figure�rhomb7;
	pointerFigure->Show();

	// ����� � 7 � ������
	Figure�rhomb7WithHole figure�rhomb7WithHole(initX, initY, initWidth, initHeight);

	//  ����� � 8
	Figure�rhomb8 figure�rhomb8(initX, initY, initWidth, initHeight);

	//  ����� � 8 � ������
	Figure�rhomb8WithHole figure�rhomb8WithHole(initX, initY, initWidth, initHeight);

	//  ����� � 10
	Figure�rhomb10 figure�rhomb10(initX + initWidth * 3, initY - 100, initWidth, initHeight);
	figure�rhomb10.Show();

	const int figureCount = 6;  // ���������� �������� �����
	const int obstacleCount = 2; // ���������� �������� ��������������

	// ������ �����
	AbstractFigure* figures[figureCount] = {
		&figure�rhomb1,
		&figure�rhomb7,
		&figure�rhomb7WithHole,
		&figure�rhomb8,
		&figure�rhomb8WithHole,
		&figure�rhomb10,
	};

	// ������ �����������
	Obstacle* obstacles[figureCount] = {
		&suit,
		&stone,
	};

	// ������� ��������� ��� ������������ � ������ �������
	int figureMatrix[figureCount][figureCount] = {
		{ -1, 0, 0, 0, 0, 0 },
		{ 3, -1, 3, 2, 2, 2 },
		{ 1, 0, -1, 0, 0, 0 },
		{ 5, 5, 5, -1, 5, 4 },
		{ 3, 3, 3, 2, -1, 2 },
		{ 5, 5, 5, 5, 5, -1 },
	};

	// ������� ��������� ��� ������������ � ������������
	int obstacleMatrix[figureCount][figureCount] = {
		{ 1, 0 },
		{ 3, 2 },
		{ 1, 0 },
		{ 5, 4 },
		{ 3, 1 },
		{ 3, 5 },
	};

	int lastIndex = 1;

	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) // Esc - ����� ������ 
		{
			return;
		}

		pointerFigure->Drag(dragValue);
		bool isHit = false, isObstableHit = false;
		int figureIndex;

		for (int i = 0; i < figureCount; i++) {
			AbstractFigure* figure = figures[i];

			if (!figure->IsVisible() || pointerFigure == figure) {
				continue;
			}

			if (pointerFigure->IsHit(figure)) {
				isHit = true;
				figure->Hide();
				figureIndex = figureMatrix[lastIndex][i];
			}
		}

		for (int i = 0; i < obstacleCount; i++) {
			Obstacle* obstacle = obstacles[i];

			if (obstacle == &suit && suit.IsVisible() && pointerFigure->IsHit(&suit)) {
				isObstableHit = true;
				figureIndex = obstacleMatrix[lastIndex][i];
				suit.Hide();
			}

			if (obstacle == &stone && stone.IsVisible() && pointerFigure->IsHit(&stone)) {
				isObstableHit = true;
				figureIndex = obstacleMatrix[lastIndex][i];
				stone.Hide();
			}
		}

		if (isHit || isObstableHit) {
			AbstractFigure* newFigurePointer = figures[figureIndex];
			pointerFigure->Hide();
			int X = pointerFigure->GetX(), Y = pointerFigure->GetY();

			newFigurePointer->Hide();
			newFigurePointer->SetX(X);
			newFigurePointer->SetY(Y);
			pointerFigure = newFigurePointer;
			pointerFigure->Show();

			lastIndex = figureIndex;
		}
	}
}