#include "Fruit.h"
#include <cstdlib>

void Fruit::SpawnFruit(int w, int h)
{
	x = rand() % w;
	y = rand() % h;
}
