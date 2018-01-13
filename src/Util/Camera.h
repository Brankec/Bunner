#pragma once
#include <SFML\Graphics.hpp>


namespace Camera
{
	void cameraZoom(sf::Event event);
	void followPlayerSmooth(sf::Vector2f entityPos, float deltaTime);

	sf::View getView(sf::Vector2f newCameraSpeed = { 0, 0 });

	static sf::View view;
	static sf::Vector2f camera;
	static sf::Vector2f cameraSpeed = { 1, 1 };
};