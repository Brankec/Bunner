#include "StatePlaying.h"

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{
	map.loadMap(levels);
}

void StatePlaying::handleEvent(sf::Event e)
{
	if (e.type == sf::Event::KeyPressed) //for switching betwen the menu and the game
	{
		if (e.key.code == sf::Keyboard::Escape)
		{
			openMenu = !openMenu;
		}
	}


	if (openMenu == false)
	{
		Camera::cameraZoom(e);
	}
	else
	{
		buttonPress(e); //checks what button was pressed
	}
}

void StatePlaying::handleInput()
{
	if (openMenu == false)
	{
		player.playerControl(); //all player controls
	}
}

void StatePlaying::update(sf::Time deltaTime)
{
	if (openMenu == false)
	{
		if (player.isFinished) //for loading other maps
		{
			nextLevel++;
			switch (nextLevel)
			{
			case 2:
				levels.Level_2();
				nextLevel++;
				break;
			default:
				nextLevel = 1;
				levels.Level_1();
				break;
			}

			map.loadMap(levels);

			player.entityRec.setPosition(30, -200);
			player.isFinished = false;
		}

		player.playerUpdate(deltaTime.asSeconds());
		Camera::followPlayerSmooth(player.getPos(), deltaTime.asSeconds());
	}
	else
	{
		ButtonUpdate(player, *shouldPop); //updates the button function
	}
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{
		renderer.setView(Camera::getView({ 10.f, 1.f })); //background scroll
		map.drawBackGround(renderer); //Background
		map.drawBackGroundMain(renderer, player); //background tiles with only top collision
		map.drawMain(renderer, player); //Main (player base)
		map.drawInteractives(renderer, player);
		renderer.draw(player.entityRec); //player
		map.drawForeGround(renderer); //Foreground
		player.gun.draw(renderer); //projectiles
		renderer.setView(renderer.getDefaultView()); //resets the view to default state

		if (openMenu)
			renderMenu(renderer);
}

void StatePlaying::pushState(bool*m_shouldPush)
{
}

void StatePlaying::popState(bool & shouldPop)
{
	this->shouldPop = &shouldPop;
}
