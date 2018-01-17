#include "mini_gun.h"



mini_gun::mini_gun()
{
	defaults();
}


mini_gun::~mini_gun()
{
}

void mini_gun::defaults()
{
	projectileSpeed = 1000;
	projectileSize = { 5, 5 };
	delayTime = 0.2;
}
