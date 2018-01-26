#include <SFML/Graphics.hpp>
#pragma once

class Button
{
public:
	Button(sf::Vector2f buttonPos, std::string fileName);

	void loadTexture(std::string fileName);
	void isButtonPressed(sf::FloatRect mousePos, sf::Event e);

public:
	sf::RectangleShape buttonRec;
	sf::Texture buttonTex;

	bool buttonPressed = false;
};