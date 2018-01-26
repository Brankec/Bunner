#include "Button.h"
#include <iostream>

Button::Button(sf::Vector2f buttonPos, std::string fileName)
{
	buttonRec.setSize({ 300,70 });
	buttonRec.setOrigin(buttonRec.getSize().x / 2, buttonRec.getSize().y / 2);
	buttonRec.setPosition(buttonPos);
	buttonRec.setTextureRect({ 0, 0, 64, 16 });
	loadTexture(fileName);
}

void Button::loadTexture(std::string fileName)
{
	if (buttonTex.loadFromFile("res/GUI/" + fileName + ".png"))
		buttonRec.setTexture(&buttonTex);
}

void Button::isButtonPressed(sf::FloatRect mousePos, sf::Event e)
{
	if (mousePos.intersects(buttonRec.getGlobalBounds()))
	{
		buttonRec.setTextureRect({ 0, 16, 64, 16 });
		if (e.type == sf::Event::MouseButtonReleased)
		{
			buttonPressed = true;
		}
	}
	else
	{
		buttonPressed = false;
		buttonRec.setTextureRect({ 0, 0, 64, 16 });
	}
}
