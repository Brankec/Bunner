#include <SFML/Graphics.hpp>
#include "Button.h"
#include "../Entities/Player.h"

#pragma once
class Menu
{
public:
	Menu();

protected:
	void buttonPress(sf::Event e);

	void ButtonUpdate(Player& player);
	void ExitWindow();
	void RestartGame(Player& player);

	void renderMenu(sf::RenderTarget& renderer);

private:
	sf::RectangleShape MenuBackground;
	sf::Texture menuTex;
	Button ExitButton, RestartButton;
};

