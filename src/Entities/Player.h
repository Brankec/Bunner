#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "../Weapons/mini_gun.h"
#include "EntitySounds/Walking.h"
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
	void playerControl();
	void playerAnimation();

	bool isJumping = false;
	bool isOnGround = true;
	mini_gun gun;

private:
	float Lerp(float x, float y, float z);
	sf::IntRect playerFrame[12][2];
	sf::Vector2u frameStage = { 0,0 };
	float frameDelay = 0;
	Walking walkingSound;

};

