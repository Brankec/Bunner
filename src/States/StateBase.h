#ifndef STATEBASE_H_INCLUDED
#define STATEBASE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <memory>

class Game;

class StateBase
{
    public:
        StateBase(Game& game) :  m_pGame   (&game)
        {}

        virtual ~StateBase() = default;

        virtual void handleEvent    (sf::Event e) = 0;
        virtual void handleInput    () = 0;
        virtual void update         (sf::Time deltaTime) = 0;
        virtual void fixedUpdate    (sf::Time deltaTime) = 0;
        virtual void render         (sf::RenderTarget& renderer) = 0;

		virtual void pushState(bool*m_shouldPush) = 0;
		virtual void popState(bool & shouldPop) = 0;

    protected:
        Game* m_pGame;
};

#endif // STATEBASE_H_INCLUDED
