#include "Map.h"

Map::Map(std::string fileNameFore, std::string fileNameBack, int n, int amountOfTiles, sf::Vector2i tileSize) 
	: openfileForeground("res/Maps/" + fileNameFore + ".txt")
	, openfileBackground("res/Maps/" + fileNameBack + ".txt")
{
	this->powOfN = (int)pow(2, n);
	this->amountOfTiles = amountOfTiles;
	this->tileSize = tileSize;
	loadTilesForeground();
	loadTilesBackground();
	//setOriginCenter();

}

void Map::setOriginCenter()
{
	tile[0].setOrigin(sf::Vector2f(tile[0].getSize().x / 2, tile[0].getSize().y / 2));
}

void Map::loadTilesForeground()
{
	if (openfileForeground.is_open())
	{
		std::string tileLocation;
		openfileForeground >> tileLocation;

		if (tileTexture.loadFromFile(tileLocation))
			tile[0].setTexture(&tileTexture);

		tile[0].setSize(sf::Vector2f((float)powOfN, (float)powOfN));
		while (openfileForeground.good())
		{
			openfileForeground >> tileIndex;
			if (tileIndex != ',')
			tempMap.push_back(Sprite_sheet_coordinates(tileIndex-1)); //the indices will always be for 1 less inside the code(so 0 is actually -1 and 1 is actually 0)

			if (openfileForeground.peek() == '\n')
			{
				mapForeGround.push_back(tempMap);
				tempMap.clear();
			}
			
		}
	}
}

void Map::loadTilesBackground()
{
	if (openfileBackground.is_open())
	{
		std::string tileLocation;
		openfileBackground >> tileLocation;

		if (tileTexture.loadFromFile(tileLocation))
			tile[1].setTexture(&tileTexture);

		tile[1].setSize(sf::Vector2f((float)powOfN, (float)powOfN));
		while (openfileBackground.good())
		{
			openfileBackground >> tileIndex;
			if (tileIndex != ',')
				tempMap.push_back(Sprite_sheet_coordinates(tileIndex - 1)); //the indices will always be for 1 less inside the code(so 0 is actually -1 and 1 is actually 0)

			if (openfileBackground.peek() == '\n')
			{
				mapBackGround.push_back(tempMap);
				tempMap.clear();
			}

		}
	}
}

void Map::drawForeGround(sf::RenderTarget& renderer, Player& player, bool (&isColliding)[4])
{
	for (int i = 0; i < mapForeGround.size(); i++)
	{
		for (int j = 0; j < mapForeGround[i].size(); j++)
		{
			if (mapForeGround[i][j].x != -1 && mapForeGround[i][j].y != -1)
			{
				tile[0].setPosition(j * (float)powOfN, i * (float)powOfN);
				tile[0].setTextureRect(sf::IntRect(mapForeGround[i][j].x, mapForeGround[i][j].y, tileSize.x, tileSize.y)); //map[i][j] holds coordinates/size of that index, not the index itself

				static sf::FloatRect collisionBound;
				collisionBound.left = tile[0].getGlobalBounds().left - 1;
				collisionBound.height = tile[0].getGlobalBounds().height + 1;
				collisionBound.width = tile[0].getGlobalBounds().width + 1;
				collisionBound.top = tile[0].getGlobalBounds().top - 1;

				if (player.getAABB().intersects(collisionBound))
				{
					if (player.velocity.x < 0 && player.getPos().x < tile[0].getPosition().x + tile[0].getGlobalBounds().width)
					{
						//std::cout << "Touched left side" << std::endl;
						isColliding[0] = true;
					}
					else
						isColliding[0] = false;

					if (player.velocity.y > 0 && player.getPos().y >= tile[0].getPosition().y)
					{
						//std::cout << "Touched Bottom" << std::endl;
						isColliding[1] = true;
					}
					else
						isColliding[1] = false;
					
					if (player.velocity.x > 0 && player.getPos().x + player.getAABB().width >= tile[0].getPosition().x)
					{
						//std::cout << "Touched right Side" << std::endl;
						isColliding[2] = true;
					}
					else
						isColliding[2] = false;

					if (player.velocity.y < 0 && player.getPos().y <= tile[0].getPosition().y)
					{
						//std::cout << "Touched Top" << std::endl;
						isColliding[3] = true;
					}
					else
						isColliding[3] = false;
				}

				renderer.draw(tile[0]);
			}
		}
	}
}

void Map::drawBackGround(sf::RenderTarget & renderer)
{
	for (int i = 0; i < mapBackGround.size(); i++)
	{
		for (int j = 0; j < mapBackGround[i].size(); j++)
		{
			if (mapBackGround[i][j].x != -1 && mapBackGround[i][j].y != -1)
			{
				tile[1].setPosition(j * (float)powOfN, i * (float)powOfN);
				tile[1].setTextureRect(sf::IntRect(mapBackGround[i][j].x, mapBackGround[i][j].y, tileSize.x, tileSize.y)); //map[i][j] holds coordinates/size of that index, not the index itself
																														//setTileTexture(map[i][j].y);
				renderer.draw(tile[1]);
			}
		}
	}
}

sf::Vector2i Map::Sprite_sheet_coordinates(int tileIndex)
{
	if (tileIndex == -1)
		return sf::Vector2i(-1, -1);//for empty cells in game
	else
	{
		sf::Vector2i coords;
		coords.x = (tileIndex % amountOfTiles) * tileSize.x;   //amount of tiles ONLY in 1 row (on the X axis)
		coords.y = (tileIndex / amountOfTiles) * tileSize.y;  //leave it like this for now


		return coords;
	}

	/*else
	{
		sf::Vector2i coords;
		coords.x = (tileIndex % 1) * 1;
		coords.y = (tileIndex / 1) * 1;
		return coords;
	}*/
}


