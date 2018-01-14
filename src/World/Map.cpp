#include "Map.h"

Map::Map(std::string fileNameFore, std::string fileNameMain, std::string fileNameBack, int n, int amountOfTiles, sf::Vector2i tileSize)
	: openfileForeground("res/Maps/" + fileNameFore + ".txt")
	, openfileMain("res/Maps/" + fileNameMain + ".txt")
	, openfileBackground("res/Maps/" + fileNameBack + ".txt")
{
	this->powOfN = (int)pow(2, n);
	this->amountOfTiles = amountOfTiles;
	this->tileSize = tileSize;
	//setOriginCenter();
	loadTilesForeground();
	loadTilesMain();
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
			tile[2].setTexture(&tileTexture);

		tile[2].setSize(sf::Vector2f((float)powOfN, (float)powOfN));
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
void Map::drawForeGround(sf::RenderTarget& renderer)
{
	for (int i = 0; i < mapForeGround.size(); i++)
	{
		for (int j = 0; j < mapForeGround[i].size(); j++)
		{
			if (mapForeGround[i][j].x != -1 && mapForeGround[i][j].y != -1)
			{
				tile[2].setPosition(j * (float)powOfN, i * (float)powOfN);
				tile[2].setTextureRect(sf::IntRect(mapForeGround[i][j].x, mapForeGround[i][j].y, tileSize.x, tileSize.y)); //map[i][j] holds coordinates/size of that index, not the index itself

				renderer.draw(tile[2]);
			}
		}
	}
}


void Map::loadTilesMain()
{
	if (openfileMain.is_open())
	{
		std::string tileLocation;
		openfileMain >> tileLocation;

		if (tileTexture.loadFromFile(tileLocation))
			tile[1].setTexture(&tileTexture);

		tile[1].setSize(sf::Vector2f((float)powOfN, (float)powOfN));
		while (openfileMain.good())
		{
			openfileMain >> tileIndex;
			if (tileIndex != ',')
				tempMap.push_back(Sprite_sheet_coordinates(tileIndex - 1)); //the indices will always be for 1 less inside the code(so 0 is actually -1 and 1 is actually 0)

			if (openfileMain.peek() == '\n')
			{
				mapMain.push_back(tempMap);
				tempMap.clear();
			}

		}
	}
}
void Map::drawMain(sf::RenderTarget & renderer, Player & player)
{
	for (int i = 0; i < mapMain.size(); i++)
	{
		for (int j = 0; j < mapMain[i].size(); j++)
		{
			if (mapMain[i][j].x != -1 && mapMain[i][j].y != -1)
			{
				tile[1].setPosition(j * (float)powOfN, i * (float)powOfN);
				tile[1].setTextureRect(sf::IntRect(mapMain[i][j].x + 1, mapMain[i][j].y + 1, tileSize.x - 2, tileSize.y - 2)); //we have to add 1 to the source and subtrack 2 from the size because of how opengl renders tiles. It causes a weird pixel gap glitch
				//map[i][j] holds coordinates/size of that index, not the index itself

				Collision(player);

				renderer.draw(tile[1]);
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
			tile[0].setTexture(&tileTexture);

		tile[0].setSize(sf::Vector2f((float)powOfN, (float)powOfN));
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
void Map::drawBackGround(sf::RenderTarget & renderer)
{
	for (int i = 0; i < mapBackGround.size(); i++)
	{
		for (int j = 0; j < mapBackGround[i].size(); j++)
		{
			if (mapBackGround[i][j].x != -1 && mapBackGround[i][j].y != -1)
			{
				tile[0].setPosition(j * (float)powOfN, i * (float)powOfN);
				tile[0].setTextureRect(sf::IntRect(mapBackGround[i][j].x + 1, mapBackGround[i][j].y + 1, tileSize.x - 2, tileSize.y - 2)); //we have to add 1 to the source and subtrack 2 from the size because of how opengl renders tiles. It causes a weird pixel gap glitch

				renderer.draw(tile[0]);
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
	float PlayerLeft = player.entityRec.getPosition().x - player.getAABB().width / 2;
	float PlayerRight = player.entityRec.getPosition().x + player.getAABB().width / 2;
	float PlayerTop = player.entityRec.getPosition().y - player.getAABB().height / 2;
	float PlayerBottom = player.entityRec.getPosition().y + player.getAABB().height / 2;

	float BlockLeft = tile[1].getPosition().x;
	float BlockRight = tile[1].getPosition().x + tile[1].getSize().x;
	float BlockTop = tile[1].getPosition().y;
	float BlockBottom = tile[1].getPosition().y + tile[1].getSize().y;

	if (PlayerRight > BlockLeft - 10 && 
		PlayerLeft < BlockRight + 10 && 
		PlayerBottom > BlockTop + 5 && 
		PlayerTop < BlockBottom - 5)
	{
		if (PlayerRight >= BlockLeft && PlayerLeft <= BlockLeft)  //Left side of the Block
		{
			player.entityRec.move(-0.5, 0);
			player.velocity.x = 0;
		}

		if (PlayerLeft <= BlockRight && PlayerRight >= BlockRight)   //Right side of the block
		{
			player.entityRec.move(-player.velocity.x, 0);
			player.entityRec.move(0.5, 0);
			player.velocity.x = 0;
		}

	}
	if (PlayerRight > BlockLeft + 5 && 
		PlayerLeft < BlockRight - 5 && 
		PlayerBottom > BlockTop - 10 && 
		PlayerTop < BlockBottom + 10)
	{
		if (PlayerTop < BlockBottom && PlayerBottom > BlockBottom)    //Bottom side of the block
		{
			player.entityRec.move(0, -player.velocity.y);
			player.velocity.y = 0;
		}

		if (PlayerBottom > BlockTop && PlayerTop < BlockTop)    //Top side of the block
		{
			player.entityRec.move(0, -player.velocity.y);
			player.velocity.y = 0;
		}
	}
}
