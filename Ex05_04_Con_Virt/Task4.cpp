#include "Task4.h" 	//���������� �������

void task4(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	AbstractFigure* pointerFigure;

	// ����� � 1
	Figure�rhomb1 figure�rhomb1(initX + initWidth * 2, initY + initHeight + 10, initWidth, initHeight);
	figure�rhomb1.Show();

	// ����� � 7
	Figure�rhomb7 figure�rhomb7(initX, initY, initWidth, initHeight);
	pointerFigure = &figure�rhomb7;
	pointerFigure->Show();

	//  ����� � 8
	Figure�rhomb8 figure�rhomb8(initX + initWidth * 2, initY - 100, initWidth, initHeight);

	//  ����� � 8 � ������
	Figure�rhomb8WithHole figure�rhomb8WithHole(initX + initWidth * 2, initY - 100, initWidth, initHeight);

	//  ����� � 10
	Figure�rhomb10 figure�rhomb10(initX + initWidth * 2, initY - 100, initWidth, initHeight);
	figure�rhomb10.Show();

	const int figureCount = 5;  // ���������� �������� �����
	const int hitObjectsCount = 4; // ���������� �������� ��������������

	// ������ �����
	AbstractFigure* figures[figureCount] = {
		&figure�rhomb1,
		&figure�rhomb7,
		&figure�rhomb8,
		&figure�rhomb8WithHole
		&figure�rhomb10,
	};

	// ������� ��������� ��� ������������ � ������ �������
	int figureMatrix[figureCount][hitObjectsCount] = {
		{ -1, 4, 3, -1, -1 },
		{ 2, -1, 0, 0, 0 },
		{ 5, 5, -1, -1, -1 },
		{ -1, -1, -1, -1, -1 },
		{ -1, -1, 5, -1, -1 },
	};

	int lastIndex = 0;

	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) // Esc - ����� ������ 
		{
			return;
		}

		pointerFigure->Drag(dragValue);

		for (int i = 0; i < figureCount; i++) {
			AbstractFigure* figure = figures[i];

			if (!figure->IsVisible() || pointerFigure == figure) {
				continue;
			}

			if (pointerFigure->IsHit(figure)) {
				figure->Hide();
				int figureIndex = figureMatrix[lastIndex][i];
				AbstractFigure* newFigurePointer = figures[figureIndex];

				pointerFigure->Hide();

				int X = pointerFigure->GetX(), Y = pointerFigure->GetY();
				newFigurePointer->SetX(X);
				newFigurePointer->SetY(Y);
				pointerFigure = newFigurePointer;
				pointerFigure->Show();

				lastIndex = i;
			}
		}
	}
}