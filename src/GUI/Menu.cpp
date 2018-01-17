#include "Menu.h"



Menu::Menu()
	: ExitButton({750,300}, "ExitButton")
{
	MenuBackground.setSize({ 900,600 });
	MenuBackground.setOrigin(MenuBackground.getSize().x / 2, MenuBackground.getSize().y / 2);
	MenuBackground.setPosition({ 750, 450 });
	MenuBackground.setFillColor(sf::Color::Black);
}

void Menu::buttonPress(sf::Event e)
{
	ExitButton.isButtonPressed({(float)e.mouseButton.x, (float)e.mouseButton.y, 1, 1}, e);
}

void Menu::ButtonUpdate()
{
	ExitWindow();
}
void Menu::ExitWindow()
{
	if (ExitButton.buttonPressed == true)
	{
		exit(-1);
	}
}
//void Menu::RestartGame









void Menu::renderMenu(sf::RenderTarget& renderer)
{
	renderer.draw(MenuBackground);
	renderer.draw(ExitButton.buttonRec);
}

