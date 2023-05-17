#include "Game.h"

int main(void)
{
	Game Snake;
	while (!Snake.GameStatus())
	{
		Snake.Draw();
		Snake.Input();
		Snake.Algorithm();
	}
    return 0;
}