#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"


class MenuState
{
public:
	MenuState();

public:
	void buttonPress(sf::Event e);

	void ExitWindow(bool& shouldPop);
	void PushPlay(bool& m_shouldPush);

	void renderMenu(sf::RenderTarget& renderer);

private:
	sf::RectangleShape MenuBackground;
	sf::Texture menuTex;
	Button ExitWindowButton, PushPlayButton;
};

