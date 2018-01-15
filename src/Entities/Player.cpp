#include "Player.h"



Player::Player()
{
	entityRec.setSize({ 25,50 });
	entityRec.setPosition(30, 400);
	entityRec.setOrigin(entityRec.getSize().x / 2, entityRec.getSize().y / 2);
	loadTextureToRec();
	loadPlayerAnimation();
	entityRec.setTextureRect(sf::IntRect(0, 0, 7, 11));

	speedMAX = 3;

	//gravity = 0.1;  for testing purposes
}

void Player::loadPlayerAnimation()
{
    //Idle stage
	playerFrame[0][0] = { 9, 0, 7, 11 }; 

	//Jump stage
	playerFrame[1][0] = { 8, 48, 7, 11 };

	//Fall stage
	playerFrame[2][0] = { 8, 64, 7, 11 };

    //moving stage
	playerFrame[0][1] = { 8, 17, 7,   10 }; 
	playerFrame[1][1] = { 24, 17, 7,  10 };
	playerFrame[2][1] = { 41, 16, 7,  11 };
	playerFrame[3][1] = { 58, 16, 7,  11 };
	playerFrame[4][1] = { 73, 16, 7,  11 };
	playerFrame[5][1] = { 88, 16, 7,  10 };
	playerFrame[6][1] = { 104, 17, 7,  10 };
	playerFrame[7][1] = { 120, 17, 7,  10 };
	playerFrame[8][1] = { 138, 16, 7,  11 };
	playerFrame[9][1] = { 154, 16, 7,  11 };
	playerFrame[10][1] = { 169, 16, 7, 11 };
	playerFrame[11][1] = { 184, 16, 7, 10 };
}

void Player::playerUpdate(float deltaTime)
{
	setPos();

	playerAnimation();
	frameDelay += deltaTime;	
}

void Player::setPos()
{
	if (getPos().y > 1000)
		entityRec.setPosition(30, 400);

	velocity.y += gravity;
	entityRec.move(velocity.x, velocity.y);
}

float Player::Lerp(float x, float y, float z) //acceleration or deceleration
{
	return ((1.0f - z) * x) + (z * y);
}

void Player::playerControl()
{
	//X axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = Lerp(velocity.x, speedMAX, 0.05f); //1) current speed ,2) max speed, 3)acceleration speed
		entityRec.setScale(1, 1); //for turning right

		if (frameStage.x < 10)
		{
			if (frameDelay > 0.25f / abs(velocity.x))
			{
				frameStage.x++;
				frameDelay = 0;
			}
		}
		else
			frameStage.x = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = Lerp(velocity.x, -speedMAX, 0.05f);
		entityRec.setScale(-1, 1); //for turning left

		if (frameStage.x < 10)
		{
			if (frameDelay > 0.25f / abs(velocity.x))
			{
				frameStage.x++;
				frameDelay = 0;
			}
		}
		else
			frameStage.x = 0;
	}
	else
	{
		frameStage.x = 0;
		velocity.x = Lerp(velocity.x, 0, 0.1f); 

		//if(abs(velocity.x) != 0)

		if(abs(velocity.x) < 0.3f)
			velocity.x = round(velocity.x);
	}
	//Y axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isJumping == false)
	{
		isJumping = true;
		velocity.y = -16;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		entityRec.setSize({ 25, 100 });

}

void Player::playerAnimation()
{

	if (velocity.x == 0)
	{
		entityRec.setTextureRect(playerFrame[0][0]); // stand still
	}
	else
	{
		entityRec.setTextureRect(playerFrame[frameStage.x][1]); //run
	}

	
	if (velocity.y < 0)
	{
		entityRec.setTextureRect(playerFrame[1][0]); // jump
	}

	else if (abs(velocity.y) > 0.81)
	{
		entityRec.setTextureRect(playerFrame[2][0]); // fall
	}
	
}


