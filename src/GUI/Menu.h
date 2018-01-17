#include <SFML/Graphics.hpp>
#include "Button.h"

#pragma once
class Menu
{
public:
	Menu();

protected:
	void buttonPress(sf::Event e);

	void ButtonUpdate();
	void ExitWindow();

	void renderMenu(sf::RenderTarget& renderer);

private:
	sf::RectangleShape MenuBackground;
	Button ExitButton;
};

