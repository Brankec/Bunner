#include "Entity.h"



Entity::Entity()
{
	isColliding[0] = false;
	isColliding[1] = false;
	isColliding[2] = false;
	isColliding[3] = false;
}

void Entity::loadTextureToRec(std::string textureName)
{
	if (entityTex.loadFromFile("res/entities/sprite/" + textureName + ".png"))
		entityRec.setTexture(&entityTex);
}

void Entity::loadTextureToSpr(std::string textureName)
{
	if (entityTex.loadFromFile("res/entities/sprite/" + textureName + ".png"))
		entitySpr.setTexture(entityTex);
}

void Entity::loadAudioBuffer(std::string audioName)
{
}

sf::FloatRect Entity::getAABB()
{
	return entityRec.getGlobalBounds();
}

sf::Vector2f Entity::getPos()
{
	return entityRec.getPosition();
}
