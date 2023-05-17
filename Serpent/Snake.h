#pragma once
#include "GameObject.h"
class Snake:public GameObject //snake.x и snake.y - координаты головы
{							//snake.Tail[i].x и snake.Tail[i].y - координаты хвоста
public:
	GameObject* Tail;
	int Length;
};

