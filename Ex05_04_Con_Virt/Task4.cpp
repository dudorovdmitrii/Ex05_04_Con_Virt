#include "Task4.h" 	//îáúÿâëåíèå êëàññîâ

void task4(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	AbstractFigure* pointerFigure;

	// Êàðòà ñ 1
	FigureÊrhomb1 figureÊrhomb1(initX + initWidth * 2, initY + initHeight + 10, initWidth, initHeight);
	figureÊrhomb1.Show();

	// Êàðòà ñ 7
	FigureÊrhomb7 figureÊrhomb7(initX, initY, initWidth, initHeight);
	pointerFigure = &figureÊrhomb7;
	pointerFigure->Show();

	//  Êàðòà ñ 8
	FigureÊrhomb8 figureÊrhomb8(initX + initWidth * 2, initY - 100, initWidth, initHeight);

	//  Êàðòà ñ 8 è äûðêîé
	FigureÊrhomb8WithHole figureÊrhomb8WithHole(initX + initWidth * 2, initY - 100, initWidth, initHeight);

	//  Êàðòà ñ 10
	FigureÊrhomb10 figureÊrhomb10(initX + initWidth * 2, initY - 100, initWidth, initHeight);
	figureÊrhomb10.Show();

	const int figureCount = 5;  // Êîëè÷åñòâî îáúåêòîâ ôèãóð
	const int hitObjectsCount = 4; // Êîëè÷åñòâî îáúåêòîâ âçàèìîäåéñòâèÿ

	// Ìàññèâ ôèãóð
	AbstractFigure* figures[figureCount] = {
		&figureÊrhomb1,
		&figureÊrhomb7,
		&figureÊrhomb8,
		&figureÊrhomb8WithHole
		&figureÊrhomb10,
	};

	// Ìàòðèöà ïåðåõîäîâ ïðè ñòîëêíîâåíèè ñ äðóãîé ôèãóðîé
	int figureMatrix[figureCount][hitObjectsCount] = {
		{ -1, 4, 3, -1, -1 },
		{ 2, -1, 0, 0, 0 },
		{ 5, 5, -1, -1, -1 },
		{ -1, -1, -1, -1, -1 },
		{ -1, -1, 5, -1, -1 },
	};

	int lastIndex = 0;

	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) // Esc - êîíåö ðàáîòû 
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