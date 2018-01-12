#pragma once
#include <SFML\Graphics.hpp>


namespace Camera
{
	void cameraZoom(sf::Event event);
	void followPlayerSmooth(sf::Vector2f entityPos, float deltaTime);

	sf::View getView();

	static sf::View view;
	static sf::Vector2f camera;
};