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
	void setPos(float collisionPos);
	void animation();
	float Lerp(float x, float y, float z);
	void playerControl();

private:
	bool isJumping = false;
	//bool isColliding[4]; // 0) left, 1) bottom, 2) right, 3) top
};

