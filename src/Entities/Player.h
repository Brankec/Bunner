#include <SFML\Graphics.hpp>
#include "Entity.h"
#include <iostream>
#include <algorithm>

#pragma once
class Player : public Entity
{
public:
	Player();

public:
	void loadPlayerAnimation();
	void playerUpdate(float deltaTime);
	void setPos();
	float Lerp(float x, float y, float z);
	void playerControl();
	void playerAnimation();

	bool isJumping = false;

private:
	sf::IntRect playerFrame[12][2];
	sf::Vector2u frameStage = { 0,0 };
	float frameDelay = 0;
};

