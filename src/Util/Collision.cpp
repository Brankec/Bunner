#include "Collision.h"



Collision::Collision(sf::RectangleShape& body)
	: body(body)
{
}


Collision::~Collision()
{
}

bool Collision::CheckCollision(const Collision& other, float push)
{
	Collision pOther = other; 

	sf::Vector2f otherPosition = pOther.GetPosition();
	sf::Vector2f otherHalfSize = pOther.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				pOther.Move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				pOther.Move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				pOther.Move(0.0f , -intersectY * push);
			}
			else
			{
				Move(0.0f , -intersectY * (1.0f - push));
				pOther.Move(0.0f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}
