#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../Entities/Player.h"
#include "../Util/Camera.h"
#include "../World/Map.h"

class StatePlaying : public StateBase
{
 public:
	 StatePlaying(Game& game);

     void handleEvent    (sf::Event e)                   override;
     void handleInput    ()                              override;
     void update         (sf::Time deltaTime)            override;
     void fixedUpdate    (sf::Time deltaTime)            override;
     void render         (sf::RenderTarget& renderer)    override;

private:
	Player player;
	Map map;
};

#endif // STATEPLAYING_H_INCLUDED