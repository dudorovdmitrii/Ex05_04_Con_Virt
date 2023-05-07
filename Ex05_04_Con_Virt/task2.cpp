#include "Task2.h" 	//объ€вление классов


void task2(int initX, int initY, int initWidth, int initHeight, int dragValue)
{
	EnemyStone enemyStone1 = EnemyStone(initX + 1000, initY, 30);
	EnemyStone enemyStone2 = EnemyStone(initX + 1000, initY + 500, 50);
	EnemyStone enemyStone3 = EnemyStone(initX + 500, initY + 500, 30);
	EnemyStone* enemyStones[enemyStoneCount] = { &enemyStone1, &enemyStone2, &enemyStone3 };

	// ƒинамический полиморфизм
	FriendStone friendStone1 = FriendStone(initX + 600, initY + 300, 30);
	Stone* friendStones[friendStoneCount] = { &friendStone1 };

	for (int i = 0; i < enemyStoneCount; i++) {
		enemyStones[i]->Show();
	}

	for (int i = 0; i < friendStoneCount; i++) {
		friendStones[i]->Show();
	}

	HittableFigure figure(initX, initY, initWidth, initHeight);
	figure.Show();

	while (true) {
		if (KEY_DOWN(VK_ESCAPE)) // Esc - конец работы 
		{
			return;
		}

		figure.Drag(dragValue);

		for (int i = 0; i < friendStoneCount; i++) {
			if (figure.IsHit(friendStones[i])) {
				if (friendStones[i]->IsVisible()) {
					friendStones[i]->Hide();
					figure.Heal();
				}
			}
		}

		for (int i = 0; i < enemyStoneCount; i++) {
			if (!enemyStones[i]->IsOnFigure() && figure.IsHit(enemyStones[i])) {
				figure.AttachHole(enemyStones[i]);
			}
		}
	}
}