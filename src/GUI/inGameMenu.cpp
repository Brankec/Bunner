#include "inGameMenu.h"



inGameMenu::inGameMenu()
	: ExitButton({ 750,600 }, "ExitButton")
	, RestartButton({ 750,400 }, "RestartButton")
{
	MenuBackground.setSize({ 1500,900 });
	MenuBackground.setOrigin(MenuBackground.getSize().x / 2, MenuBackground.getSize().y / 2);
	MenuBackground.setPosition({ 750, 450 });
	if (menuTex.loadFromFile("res/GUI/menu_background.png"))
	MenuBackground.setTexture(&menuTex);
}

void inGameMenu::buttonPress(sf::Event e)
{
	ExitButton.isButtonPressed({(float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1}, e);
	RestartButton.isButtonPressed({ (float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1 }, e);
}

void inGameMenu::ButtonUpdate(Player& player, bool & shouldPop)
{
	ExitWindow(shouldPop);
	RestartGame(player);
}
void inGameMenu::ExitWindow(bool & shouldPop)
{
	if (ExitButton.buttonPressed == true)
	{
		shouldPop = true;
	}
}
void inGameMenu::RestartGame(Player& player)
{
	if (RestartButton.buttonPressed == true)
	{
		player.velocity.y = 0;
		player.entityRec.setPosition(900, 150);
	}
}






void inGameMenu::renderMenu(sf::RenderTarget& renderer)
{
	renderer.draw(MenuBackground);
	renderer.draw(ExitButton.buttonRec);
	renderer.draw(RestartButton.buttonRec);
}

