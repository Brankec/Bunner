#include <SFML\Graphics.hpp>
#include "Entity.h"
#include <iostream>

#pragma once
class Player : public Entity
{
public:
	Player();

public:
	void playerUpdate();
	void setPos();
	void animation();
	float Lerp(float x, float y, float z);
	void playerControl();

	//Collision GetCollision() { return Collision(entityRec); }

private:
	bool isJumping = false;
};

