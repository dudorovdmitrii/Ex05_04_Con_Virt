#include "Task3.h" 	//объявление классов

void task3(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	// Пустая фигура
	FigureBlank* pointerFigure;
	FigureBlank figureBlank(initX, initY, initWidth, initHeight);
	pointerFigure = &figureBlank;
	pointerFigure->Show();

	// Масть
	Suit* pointerSuit;
	Suit suit(1500, 100, initWidth / 2, initHeight / 2);
	pointerSuit = &suit;
	pointerSuit->Show();

	// Число
	Number* pointerNumber;
	Number number(1500, 600, initWidth / 10, initHeight / 10);
	pointerNumber = &number;
	pointerNumber->Show();

	// Камень
	Stone* pointerStone;
	Stone stone(800, 850, 30);
	pointerStone = &stone;
	pointerStone->Show();

	// Непустые фигуры
	FigureWithNumber figureWithNumber = FigureWithNumber(initX, initY, initWidth, initHeight);
	FigureWithSuit figureWithSuit = FigureWithSuit(initX, initY, initWidth, initHeight);
	FigureWithHole figureWithHole = FigureWithHole(initX, initY, initWidth, initHeight);
	FigureWithNumberAndSuit figureWithNumberAndSuit = FigureWithNumberAndSuit(initX, initY, initWidth, initHeight);
	FigureWithNumberAndHole figureWithNumberAndHole = FigureWithNumberAndHole(initX, initY, initWidth, initHeight);
	FigureWithSuitAndHole figureWithSuitAndHole = FigureWithSuitAndHole(initX, initY, initWidth, initHeight);
	FigureComplete figureComplete = FigureComplete(initX, initY, initWidth, initHeight);

	const int figureCount = 8;  // Количество объектов фигур
	const int hitObjectsCount = 3; // Количество объектов взаимодействия
	
	// Массив непустых фигур
	FigureBlank* figures[figureCount] = {
		&figureBlank,
		&figureWithNumber,
		&figureWithSuit,
		&figureWithHole,
		&figureWithNumberAndSuit,
		&figureWithNumberAndHole,
		&figureWithSuitAndHole,
		&figureComplete,
	};

	// Массив объектов, взаимодейсвующих с фигурой
	VirtualPoint* hitObjects[hitObjectsCount] = { pointerNumber, pointerSuit, pointerStone};

	// Матрица переходов
	int matrix[figureCount][hitObjectsCount] = {
		{ 1, 2, 3 },
		{ -1, 4, 5 }, 
		{ 4, -1, 6 },
		{ 5, 6, -1 },
		{ -1, -1, 7 },
		{ -1, 7, -1 },
		{ 7, -1, -1 },
		{ -1, -1, -1 },
	};

	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) // Esc - конец работы 
		{
			return;
		}

		pointerFigure->Drag(dragValue);

		for (int i = 0; i < hitObjectsCount; i++) {
			if (!hitObjects[i]->IsVisible()) {
				continue;
			}

			bool isHit = false;

			if (hitObjects[i] == pointerStone) {
				if (pointerFigure->IsHit(pointerStone)) {
					isHit = true;
					pointerStone->Hide();
				}
			}

			if (hitObjects[i] == pointerNumber) {
				if (pointerFigure->IsHit(pointerNumber)) {
					isHit = true;
					pointerNumber->Hide();
				}
			}

			if (hitObjects[i] == pointerSuit) {
				if (pointerFigure->IsHit(pointerSuit)) {
					isHit = true;
					pointerSuit->Hide();
				}
			}

			if (isHit) {
				FigureBlank* newFigurePointer = pointerFigure;

				for (int j = 0; j < figureCount; j++) {
					if (figures[j] == pointerFigure) {
						int figureIndex = matrix[j][i];
						newFigurePointer = figures[figureIndex];
						break;
					}
				}

				pointerFigure->Hide();
				
				int X = pointerFigure->GetX(), Y = pointerFigure->GetY();
				newFigurePointer->SetX(X);
				newFigurePointer->SetY(Y);
				pointerFigure = newFigurePointer;
				pointerFigure->Show();
			}

		}
	}
}