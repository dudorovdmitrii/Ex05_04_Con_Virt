#include "Task1.h" 	//���������� �������


void task1(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	int linkType;
	cout << "������/������� ���������� (0/1): ";
	cin >> linkType;
	if (linkType == 0) {
		BaseFigure figure(initX, initY, initWidth, initHeight);
		figure.Show();

		while (true) {
			if (KEY_DOWN(VK_ESCAPE)) // Esc -  ����� ������ 
			{
				return;
			}

			figure.Drag(dragValue);
		}
	}
	else {
		VirtualFigure figure(initX, initY, initWidth, initHeight);
		figure.Show();

		while (true) {
			if (KEY_DOWN(VK_ESCAPE)) // Esc - ����� ������ 
			{
				return;
			}

			figure.Drag(dragValue);
		}
	}
}