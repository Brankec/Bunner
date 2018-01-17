#pragma
#include <SFML/Graphics.hpp>
#include "StateBase.h"

class MenuState : public StateBase
{
public:
	MenuState(Game& game);

	void handleEvent(sf::Event e)                   override;
	void handleInput()                              override;
	void update(sf::Time deltaTime)                 override;
	void fixedUpdate(sf::Time deltaTime)            override;
	void render(sf::RenderTarget& renderer)         override;

private:
};