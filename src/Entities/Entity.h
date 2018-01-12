#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>

#pragma once
class Entity
{
public:
	Entity();
	void loadTextureToRec(std::string textureName = "entities");
	void loadTextureToSpr(std::string textureName = "entities");
	void loadAudioBuffer(std::string audioName = "placeholder");

	sf::FloatRect getAABB();
	sf::Vector2f getPos();

public:
	sf::RectangleShape entityRec;
	sf::Texture entityTex;
	sf::Sprite entitySpr;
	sf::SoundBuffer entityBuffer;
	sf::Sound entitySound;

	bool isColliding[4]; // 0) left, 1) bottom, 2) right, 3) top
	float speedMAX = 10;
	float gravity = 0.18f;
	sf::Vector2f velocity = { 0, 0 };
};