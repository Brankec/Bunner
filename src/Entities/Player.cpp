#include "Player.h"



Player::Player()
{
	entityRec.setSize({ 50,50 });
	entityRec.setPosition(0, 400);
	loadTextureToRec();
	entityRec.setTextureRect(sf::IntRect(8, 209, 7, 10));
}

void Player::playerUpdate()
{
	setPos(390);
}

void Player::setPos(float collisionPos)
{
	/*if (!isColliding)
	{
		isJumping = false;
		//velocity.y = velocity.y + gravity;
	}
	else
	{
		velocity.y = 0;

		isJumping = false;

		entityRec.setPosition({ getPos().x, collisionPos });
	}*/
	if (isColliding[0])
	{
		//entityRec.move(10, 0);
		std::cout << "Colliding left" << std::endl;
	}

	entityRec.move(velocity.x, velocity.y);
}

void Player::animation()
{
	//entityRec.setTextureRect(sf::IntRect(5, 5, 6, 4));  //5,5,6,4
}

float Player::Lerp(float x, float y, float z) //acceleration or deacceleration
{
	return ((1.0f - z) * x) + (z * y);
}

void Player::playerControl()
{
	//X axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = Lerp(velocity.x, 6, 0.05f); //1) current speed ,2) max speed, 3)acceleration speed
		//velocity.x = 5;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = Lerp(velocity.x, -6, 0.05f);
		//velocity.x = -5;
	}
	else
	{
		velocity.x = Lerp(velocity.x, 0, 0.1f); 

		if(abs(velocity.x) < 0.3f)
			velocity.x = round(velocity.x);
	}
	//Y axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isJumping == false)
	{
		isJumping = true;
		velocity.y = -22;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -5;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y = 5;
	}
	else
		velocity.y = 0;*/
}


