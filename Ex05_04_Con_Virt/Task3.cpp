//#include "Task3.h" 	//îáúÿâëåíèå êëàññîâ
//
//void task3(int initX, int initY, int initWidth, int initHeight, int dragValue)
//{
//	FigureBlank* pointerFigure;
//
//	// Êàðòà ñ 1
//	FigureÊrhomb1 figureÊrhomb1(initX + initWidth * 2, initY + initHeight + 10, initWidth, initHeight);
//	figureÊrhomb1.Show();
//
//	// Êàðòà ñ 7
//	FigureÊrhomb7 figureÊrhomb7(initX, initY, initWidth, initHeight);
//	pointerFigure = &figureÊrhomb7;
//	pointerFigure->Show();
//
//	//  Êàðòà ñ 10
//	FigureÊrhomb10 figureÊrhomb10(initX + initWidth * 2, initY - 100, initWidth, initHeight);
//	figureÊrhomb10.Show();
//
//	//  Êàðòà ñ 10
//	FigureÊrhomb8WithHole figureÊrhomb8WithHole(initX + initWidth * 2, initY - 100, initWidth, initHeight);
//
//	//  Êàðòà ñ 8
//	FigureÊrhomb8 figureÊrhomb8(initX + initWidth * 2, initY - 100, initWidth, initHeight);
//
//	// Íåïóñòûå ôèãóðû
//	FigureWithNumber figureWithNumber = FigureWithNumber(initX, initY, initWidth, initHeight);
//	FigureWithSuit figureWithSuit = FigureWithSuit(initX, initY, initWidth, initHeight);
//	FigureWithHole figureWithHole = FigureWithHole(initX, initY, initWidth, initHeight);
//	FigureWithNumberAndSuit figureWithNumberAndSuit = FigureWithNumberAndSuit(initX, initY, initWidth, initHeight);
//	FigureWithNumberAndHole figureWithNumberAndHole = FigureWithNumberAndHole(initX, initY, initWidth, initHeight);
//	FigureWithSuitAndHole figureWithSuitAndHole = FigureWithSuitAndHole(initX, initY, initWidth, initHeight);
//	FigureComplete figureComplete = FigureComplete(initX, initY, initWidth, initHeight);
//
//	const int figureCount = 6;  // Êîëè÷åñòâî îáúåêòîâ ôèãóð
//	const int hitObjectsCount = 4; // Êîëè÷åñòâî îáúåêòîâ âçàèìîäåéñòâèÿ
//
//	// Ìàññèâ íåïóñòûõ ôèãóð
//	FigureBlank* figures[figureCount] = {
//		&figureÊrhomb7,
//		&figureÊrhomb1,
//		&figureÊrhomb10,
//		&figureComplete,
//		&figureÊrhomb8,
//		&figureÊrhomb8WithHole
//	};
//
//	// Ìàòðèöà ïåðåõîäîâ
//	int matrix[figureCount][hitObjectsCount] = {
//		{ -1, 4, 3, -1 },
//		{ 5, -1, 5, -1 },
//		{ 5, 5, -1, -1 },
//		{ -1, -1, -1, -1 },
//		{ -1, -1, 5, -1 },
//	};
//
//	int lastIndex = 0;
//
//	while (true) {
//		if (KEY_DOWN(VK_ESCAPE)) // Esc - êîíåö ðàáîòû 
//		{
//			return;
//		}
//
//		pointerFigure->Drag(dragValue);
//
//		for (int i = 0; i < figureCount; i++) {
//			FigureBlank* figure = figures[i];
//
//			if (!figure->IsVisible() || pointerFigure == figure) {
//				continue;
//			}
//
//			if (pointerFigure->IsHit(figure)) {
//				figure->Hide();
//				int figureIndex = matrix[lastIndex][i];
//				FigureBlank* newFigurePointer = figures[figureIndex];
//
//				pointerFigure->Hide();
//
//				int X = pointerFigure->GetX(), Y = pointerFigure->GetY();
//				newFigurePointer->SetX(X);
//				newFigurePointer->SetY(Y);
//				pointerFigure = newFigurePointer;
//				pointerFigure->Show();
//
//				lastIndex = i;
//			}
//		}
//	}
//}