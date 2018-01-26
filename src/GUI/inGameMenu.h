#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "../Entities/Player.h"


class inGameMenu
{
public:
	inGameMenu();

protected:
	void buttonPress(sf::Event e);

	void ButtonUpdate(Player& player, bool & shouldPop);
	void ExitWindow(bool & shouldPop);
	void RestartGame(Player& player);

	void renderMenu(sf::RenderTarget& renderer);

private:
	sf::RectangleShape MenuBackground;
	sf::Texture menuTex;
	Button ExitButton, RestartButton;
};

