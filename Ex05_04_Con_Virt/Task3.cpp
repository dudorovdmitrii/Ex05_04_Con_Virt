#include "Task3.h" 	//���������� �������

void task3(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	FigureBlank* pointerFigure;

	// ����� � 1
	Figure�rhomb1 figure�rhomb1(initX + initWidth * 2, initY + initHeight + 10, initWidth, initHeight);
	figure�rhomb1.Show();

	// ����� � 7
	Figure�rhomb7 figure�rhomb7(initX, initY, initWidth, initHeight);
	pointerFigure = &figure�rhomb7;
	pointerFigure->Show();

	//  ����� � 10
	Figure�rhomb10 figure�rhomb10(initX + initWidth * 2, initY - 100, initWidth, initHeight);
	figure�rhomb10.Show();

	//  ����� � 10
	Figure�rhomb8WithHole figure�rhomb8WithHole(initX + initWidth * 2, initY - 100, initWidth, initHeight);

	//  ����� � 8
	Figure�rhomb8 figure�rhomb8(initX + initWidth * 2, initY - 100, initWidth, initHeight);

	// �������� ������
	FigureWithNumber figureWithNumber = FigureWithNumber(initX, initY, initWidth, initHeight);
	FigureWithSuit figureWithSuit = FigureWithSuit(initX, initY, initWidth, initHeight);
	FigureWithHole figureWithHole = FigureWithHole(initX, initY, initWidth, initHeight);
	FigureWithNumberAndSuit figureWithNumberAndSuit = FigureWithNumberAndSuit(initX, initY, initWidth, initHeight);
	FigureWithNumberAndHole figureWithNumberAndHole = FigureWithNumberAndHole(initX, initY, initWidth, initHeight);
	FigureWithSuitAndHole figureWithSuitAndHole = FigureWithSuitAndHole(initX, initY, initWidth, initHeight);
	FigureComplete figureComplete = FigureComplete(initX, initY, initWidth, initHeight);

	const int figureCount = 6;  // ���������� �������� �����
	const int hitObjectsCount = 4; // ���������� �������� ��������������

	// ������ �������� �����
	FigureBlank* figures[figureCount] = {
		&figure�rhomb7,
		&figure�rhomb1,
		&figure�rhomb10,
		&figureComplete,
		&figure�rhomb8,
		&figure�rhomb8WithHole
	};

	// ������� ���������
	int matrix[figureCount][hitObjectsCount] = {
		{ -1, 4, 3, -1 },
		{ 5, -1, 5, -1 },
		{ 5, 5, -1, -1 },
		{ -1, -1, -1, -1 },
		{ -1, -1, 5, -1 },
	};

	int lastIndex = 0;

	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) // Esc - ����� ������ 
		{
			return;
		}

		pointerFigure->Drag(dragValue);

		for (int i = 0; i < figureCount; i++) {
			FigureBlank* figure = figures[i];

			if (!figure->IsVisible() || pointerFigure == figure) {
				continue;
			}

			if (pointerFigure->IsHit(figure)) {
				figure->Hide();
				int figureIndex = matrix[lastIndex][i];
				FigureBlank* newFigurePointer = figures[figureIndex];

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