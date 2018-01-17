#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>

#pragma once
class Entity
{
public:
	Entity();
	void loadTextureToRec(std::string textureName = "player_all_positions");
	void loadTextureToSpr(std::string textureName = "entities");
	void loadAudioBuffer(std::string audioName = "placeholder");

	sf::FloatRect getAABB();
	sf::Vector2f getPos();

public:
	sf::RectangleShape entityRec;
	sf::Texture entityTex;
	sf::Sprite entitySpr;

	float speedMAX = 0;
	float gravity = 0.6f;
	sf::Vector2f velocity = { 0, 0 };

	int Angle = 90;

protected:
	int currentHealth = 10;
	int maxHealth = 10;
};
