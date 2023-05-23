#include "Task4.h" 	//îáúÿâëåíèå êëàññîâ

void task4(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	AbstractFigure* pointerFigure;

	Suit suit(initX + initWidth * 2, initY + initHeight, initWidth / 2, initHeight / 2);
	suit.Show();

	Stone stone(initX + initWidth * 2, initY, 30);
	stone.Show();

	// Êàðòà ñ 1
	FigureÊrhomb1 figureÊrhomb1(initX + initWidth * 3, initY + initHeight + 10, initWidth, initHeight);
	figureÊrhomb1.Show();

	// Êàðòà ñ 7
	FigureÊrhomb7 figureÊrhomb7(initX, initY, initWidth, initHeight);
	pointerFigure = &figureÊrhomb7;
	pointerFigure->Show();

	// Êàðòà ñ 7 è äûðêîé
	FigureÊrhomb7WithHole figureÊrhomb7WithHole(initX, initY, initWidth, initHeight);

	//  Êàðòà ñ 8
	FigureÊrhomb8 figureÊrhomb8(initX, initY, initWidth, initHeight);

	//  Êàðòà ñ 8 è äûðêîé
	FigureÊrhomb8WithHole figureÊrhomb8WithHole(initX, initY, initWidth, initHeight);

	//  Êàðòà ñ 10
	FigureÊrhomb10 figureÊrhomb10(initX + initWidth * 3, initY - 100, initWidth, initHeight);
	figureÊrhomb10.Show();

	const int figureCount = 6;  // Êîëè÷åñòâî îáúåêòîâ ôèãóð
	const int obstacleCount = 2; // Êîëè÷åñòâî îáúåêòîâ âçàèìîäåéñòâèÿ

	// Ìàññèâ ôèãóð
	AbstractFigure* figures[figureCount] = {
		&figureÊrhomb1,
		&figureÊrhomb7,
		&figureÊrhomb7WithHole,
		&figureÊrhomb8,
		&figureÊrhomb8WithHole,
		&figureÊrhomb10,
	};

	// Ìàññèâ ïðåïÿòñòâèé
	Obstacle* obstacles[figureCount] = {
		&suit,
		&stone,
	};

	// Ìàòðèöà ïåðåõîäîâ ïðè ñòîëêíîâåíèè ñ äðóãîé ôèãóðîé
	int figureMatrix[figureCount][figureCount] = {
		{ -1, 0, 0, 0, 0, 0 },
		{ 3, -1, 3, 2, 2, 2 },
		{ 1, 0, -1, 0, 0, 0 },
		{ 5, 5, 5, -1, 5, 4 },
		{ 3, 3, 3, 2, -1, 2 },
		{ 5, 5, 5, 5, 5, -1 },
	};

	// Ìàòðèöà ïåðåõîäîâ ïðè ñòîëêíîâåíèè ñ ïðåïÿòñòâèåì
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
		if (KEY_DOWN(VK_ESCAPE)) // Esc - êîíåö ðàáîòû 
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