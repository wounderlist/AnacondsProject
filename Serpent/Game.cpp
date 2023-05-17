#include "Game.h"

Game::Game():score(0),gamestatus(false),dir(STOP)
{
	snake.Tail = new GameObject[100];
	snake.x = field.w / 2;
	snake.y = field.h / 2;
	fruit.SpawnFruit(field.w, field.h); //поменять координаты фрукта
	snake.Length = 0;
	game_time = time(NULL);
}

Game::~Game()
{
	delete[] snake.Tail;
}

void Game::Draw()
{
	{
		system("cls");
		for (int i = 0; i < field.w + 2; i++)
			cout << "#";
		cout << endl;
		for (int i = 0; i < field.h; i++) 
		{
			for (int j = 0; j < field.w; j++) 
			{
				if (j == 0)
					cout << "#"; //стены
				if (i ==snake.y && j == snake.x)
					cout << "*"; // змея
				else if (i == fruit.y && j == fruit.x)
					cout << "%"; // фрукт
				else 
				{
					bool print = false;
					for (int k = 0; k < snake.Length; k++) {
						if ((*(snake.Tail+k)).x == j && (*(snake.Tail + k)).y == i)
						{
							cout << "*"; print = true;
						}
					}
					if (!print) cout << " ";
				}
				if (j == field.w - 1)
					cout << "#";
			}
			cout << endl;
		}
		for (int i = 0; i < field.w + 2; i++)
			cout << "#";
		cout << endl;
		cout << "Score:" << GetScore() << endl;
		cout << "Tale:" << snake.Length << endl;
		cur_time = time(NULL);
		cout << "Time in game:" << '\t' << cur_time - game_time << " sec" << endl;
	}
}

void Game::Input()
{
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				ChangeGameStatus(true);
				break;
			}
		}
	}
}

void Game::Algorithm()
{
	{
		int prevX = (*(snake.Tail)).x;
		int prevY = (*(snake.Tail)).y;
		int prev2X, prev2Y;
		(*(snake.Tail)).x = snake.x;
		(*(snake.Tail)).y = snake.y;
		for (int i = 1; i < snake.Length; i++) 
		{
			prev2X = (*(snake.Tail + i)).x;
			prev2Y = (*(snake.Tail + i)).y;
			(*(snake.Tail + i)).x = prevX;
			(*(snake.Tail + i)).y = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		switch (dir) 
		{
		case LEFT:
			snake.x--;
			break;
		case RIGHT:
			snake.x++;
			break;
		case UP:
			snake.y--;
			break;
		case DOWN:
			snake.y++;
			break;
		default:
			break;
		}
		if (snake.x >= field.w)
			snake.x = 0;
		else if (snake.x < 0)
			snake.x = field.w - 1;
		if (snake.y >= field.h)
			snake.y = 0;
		else if (snake.y < 0)
			snake.y = field.h - 1;
		for (int i = 0; i < snake.Length; i++)
			if ((*(snake.Tail + i)).x == snake.x && (*(snake.Tail + i)).y == snake.y)
				ChangeGameStatus(true);
		if (snake.x == fruit.x && snake.y == fruit.y) {
			ChangeScore();
			fruit.SpawnFruit(field.w, field.h);
			snake.Length++;
		}
	}
}

bool Game::GameStatus()
{
	return gamestatus;
}

void Game::ChangeGameStatus(bool statuscur)
{
	gamestatus = statuscur;
}

int Game::GetScore()
{
	return score;
}

void Game::ChangeScore()
{
	score+=10;
}
