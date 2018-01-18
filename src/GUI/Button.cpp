#include "Button.h"

Button::Button(sf::Vector2f buttonPos, std::string fileName)
{
	buttonRec.setSize({ 300,70 });
	buttonRec.setOrigin(buttonRec.getSize().x / 2, buttonRec.getSize().y / 2);
	buttonRec.setPosition(buttonPos);
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
		buttonRec.setFillColor(sf::Color::Red);
		if (e.type == sf::Event::MouseButtonReleased)
		{
			buttonPressed = true;
		}
	}
	else
	{
		buttonPressed = false;
		buttonRec.setFillColor(sf::Color::White);
	}
}
