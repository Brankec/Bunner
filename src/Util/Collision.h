#include "SFML\Graphics.hpp"
#include <algorithm>
#include <iostream>

#pragma once
class Collision
{
public:
	Collision(sf::RectangleShape& body);
	~Collision();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(const Collision& other, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};

