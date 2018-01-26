#include "MenuState.h"
#include <iostream>


MenuState::MenuState()
	: ExitWindowButton({ 750,600 }, "ExitButton")
	, PushPlayButton({ 750,300 }, "PlayButton")
{
	MenuBackground.setSize({ 1500, 1000 });
	MenuBackground.setFillColor(sf::Color::Black);
}

void MenuState::buttonPress(sf::Event e)
{
	ExitWindowButton.isButtonPressed({ (float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1 }, e);
	PushPlayButton.isButtonPressed({ (float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1 }, e);
}

void MenuState::ExitWindow(bool& shouldPop)
{
	if (ExitWindowButton.buttonPressed == true)
	{
		shouldPop = true;
	}
}

void MenuState::PushPlay(bool& m_shouldPush)
{
	if (PushPlayButton.buttonPressed == true)
	{
		m_shouldPush = true;
		PushPlayButton.buttonPressed = false;
	}
}




void MenuState::renderMenu(sf::RenderTarget& renderer)
{
	renderer.draw(MenuBackground);
	renderer.draw(ExitWindowButton.buttonRec);
	renderer.draw(PushPlayButton.buttonRec);
}

