#include "Player.h"



Player::Player()
{
	entityRec.setSize({ 25,50 });
	entityRec.setPosition(0, 400);
	entityRec.setOrigin(entityRec.getSize().x / 2, entityRec.getSize().y / 2);
	loadTextureToRec();
	entityRec.setTextureRect(sf::IntRect(8, 209, 7, 10));

	speedMAX = 4;
}

void Player::playerUpdate()
{
	setPos();
}

void Player::setPos()
{
	if (velocity.y < 0)
	{
	}
	else
	{
		isJumping = false;
	}
	/*if (isColliding[0])
	{
		//entityRec.move(10, 0);
		std::cout << "Colliding left" << std::endl;

		//entityRec.move(-velocity.x, 0);
		//velocity.x = 0;
	}
	if (isColliding[1])
	{
		//entityRec.move(10, 0);
		std::cout << "Colliding right" << std::endl;

		//entityRec.move(-velocity.x, 0);
		//velocity.x = 0;
	}
	if (isColliding[2])
	{
		//entityRec.move(10, 0);
		//velocity.x = 0;
		std::cout << "Colliding top" << std::endl;

		//entityRec.move(0, -velocity.y);
		//velocity.y = 0;
	}
	if (isColliding[3])
	{
		//entityRec.move(10, 0);
		std::cout << "Colliding bottom" << std::endl;

		//entityRec.move(0, -velocity.y);
		//velocity.y = 0;
	}*/


	velocity.y += gravity;
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
		velocity.x = Lerp(velocity.x, speedMAX, 0.05f); //1) current speed ,2) max speed, 3)acceleration speed
		entityRec.setScale(1, 1);
		//velocity.x = 2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = Lerp(velocity.x, -speedMAX, 0.05f);
		entityRec.setScale(-1, 1);
		//velocity.x = -2;
	}
	else
	{
		velocity.x = Lerp(velocity.x, 0, 0.1f); 

		if(abs(velocity.x) < 0.3f)
			velocity.x = round(velocity.x);
		//velocity.x = 0;
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


