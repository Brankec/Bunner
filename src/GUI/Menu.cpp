#include "Menu.h"



Menu::Menu()
	: ExitButton({ 750,300 }, "ExitButton")
	, RestartButton({ 750,400 }, "RestartButton")
{
	MenuBackground.setSize({ 1500,900 });
	MenuBackground.setOrigin(MenuBackground.getSize().x / 2, MenuBackground.getSize().y / 2);
	MenuBackground.setPosition({ 750, 450 });
	if (menuTex.loadFromFile("res/GUI/menu_background.png"))
	MenuBackground.setTexture(&menuTex);
}

void Menu::buttonPress(sf::Event e)
{
	ExitButton.isButtonPressed({(float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1}, e);
	RestartButton.isButtonPressed({ (float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1 }, e);
}

void Menu::ButtonUpdate(Player& player)
{
	ExitWindow();
	RestartGame(player);
}
void Menu::ExitWindow()
{
	if (ExitButton.buttonPressed == true)
	{
		exit(-1);
	}
}
void Menu::RestartGame(Player& player)
{
	if (RestartButton.buttonPressed == true)
	{
		player.velocity.y = 0;
		player.entityRec.setPosition(900, 150);
	}
}






void Menu::renderMenu(sf::RenderTarget& renderer)
{
	renderer.draw(MenuBackground);
	renderer.draw(ExitButton.buttonRec);
	renderer.draw(RestartButton.buttonRec);
}

