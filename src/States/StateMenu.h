#pragma
#include <SFML/Graphics.hpp>
#include "StateBase.h"
#include "../GUI/MenuState.h"

class StateMenu
	: public StateBase
	, public MenuState
{
public:
	StateMenu(Game& game);

	void handleEvent(sf::Event e)                   override;
	void handleInput()                              override;
	void update(sf::Time deltaTime)                 override;
	void fixedUpdate(sf::Time deltaTime)            override;
	void render(sf::RenderTarget& renderer)         override;

	void pushState(bool*m_shouldPush)               override;
	void popState(bool & shouldPop)                 override;

private:
	std::stack<std::unique_ptr<StateBase>>* m_states;
};