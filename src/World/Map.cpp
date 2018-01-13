#include "Map.h"

Map::Map(std::string fileNameFore, std::string fileNameBack, int n, int amountOfTiles, sf::Vector2i tileSize) 
	: openfileForeground("res/Maps/" + fileNameFore + ".txt")
	, openfileBackground("res/Maps/" + fileNameBack + ".txt")
{
	this->powOfN = (int)pow(2, n);
	this->amountOfTiles = amountOfTiles;
	this->tileSize = tileSize;
	//setOriginCenter();
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

void Map::drawForeGround(sf::RenderTarget& renderer, Player& player)
{
	for (int i = 0; i < mapForeGround.size(); i++)
	{
		for (int j = 0; j < mapForeGround[i].size(); j++)
		{
			if (mapForeGround[i][j].x != -1 && mapForeGround[i][j].y != -1)
			{
				tile[0].setPosition(j * (float)powOfN, i * (float)powOfN);
				tile[0].setTextureRect(sf::IntRect(mapForeGround[i][j].x, mapForeGround[i][j].y, tileSize.x, tileSize.y)); //map[i][j] holds coordinates/size of that index, not the index itself

				Collision(player);

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

void Map::Collision(Player &player)
{
	float PlayerLeft = player.entityRec.getPosition().x;
	float PlayerRight = player.entityRec.getPosition().x + 25;
	float PlayerTop = player.entityRec.getPosition().y;
	float PlayerBottom = player.entityRec.getPosition().y + 50;

	float BlockLeft = tile[0].getPosition().x;
	float BlockRight = tile[0].getPosition().x + tile[0].getSize().x;
	float BlockTop = tile[0].getPosition().y;
	float BlockBottom = tile[0].getPosition().y + tile[0].getSize().y;

	if (PlayerRight > BlockLeft - 5 && 
		PlayerLeft < BlockRight + 5 && 
		PlayerBottom > BlockTop + 5 && 
		PlayerTop < BlockBottom - 5)
	{
		if (PlayerRight >= BlockLeft && PlayerLeft <= BlockLeft)  //Left side of the Block
		{
			player.isColliding[0] = true;
			player.entityRec.move(-player.velocity.x, 0);
			player.velocity.x = 0;
		}
		else
			player.isColliding[0] = false;

		if (PlayerLeft <= BlockRight && PlayerRight >= BlockRight)   //Right side of the block
		{
			player.isColliding[1] = true;
			player.entityRec.move(-player.velocity.x, 0);
			player.velocity.x = 0;
		}
		else
			player.isColliding[1] = false;

	}
	if (PlayerRight > BlockLeft + 5 && 
		PlayerLeft < BlockRight - 5 && 
		PlayerBottom > BlockTop - 5 && 
		PlayerTop < BlockBottom + 5)
	{
		if (PlayerTop < BlockBottom && PlayerBottom > BlockBottom)    //Bottom side of the block
		{
			player.isColliding[2] = true;
			player.entityRec.move(0, -player.velocity.y);
			player.velocity.y = 0;
		}
		else
		{
			player.isColliding[2] = false;
		}

		if (PlayerBottom > BlockTop && PlayerTop < BlockTop)    //Top side of the block
		{
			player.isColliding[3] = true;
			player.entityRec.move(0, -player.velocity.y);
			player.velocity.y = 0;
		}
		else
			player.isColliding[3] = false;
		
	}
}
