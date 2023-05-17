#pragma once
#include < iostream >
#include < conio.h >
#include <time.h>
#include "GameObject.h"
#include "Field.h"
#include "Fruit.h"
#include "Snake.h"
using std::cout;
using std::endl;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN }; // Controls
class Game
{
public:
	Field field;
	Fruit fruit;
	Snake snake;
	eDirecton dir;
	time_t game_time;
	time_t cur_time;
private:
	bool gamestatus;
	int score;

public:
	Game();
	~Game();
	void Draw();
	void Input();
	void Algorithm();
	bool GameStatus();
	void ChangeGameStatus(bool);
	int GetScore();
	void ChangeScore();
};

