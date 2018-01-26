#include "StateMenu.h"

StateMenu::StateMenu(Game & game)
	: StateBase(game)
{
}

void StateMenu::handleEvent(sf::Event e)
{
	buttonPress(e);
}

void StateMenu::handleInput()
{
}

void StateMenu::update(sf::Time deltaTime)
{
}

void StateMenu::fixedUpdate(sf::Time deltaTime)
{
}

void StateMenu::render(sf::RenderTarget & renderer)
{
	renderMenu(renderer);
}

void StateMenu::pushState(bool*m_shouldPush)
{
	PushPlay(m_shouldPush[0]);
}

void StateMenu::popState(bool & shouldPop)
{
	ExitWindow(shouldPop);
}
