#pragma once
#include "GameObject.h"
class Snake:public GameObject //snake.x � snake.y - ���������� ������
{							//snake.Tail[i].x � snake.Tail[i].y - ���������� ������
public:
	GameObject* Tail;
	int Length;
};

