#include "FPSCounter.h"

#include <iostream>

FPSCounter::FPSCounter()
{
    m_text.move(10, 10);
    m_text.setOutlineColor (sf::Color::Black);
    m_text.setFillColor({255,255,255});
    m_text.setOutlineThickness  (2);

	if (m_font.loadFromFile("res/GUI/AGENCYR.TTF"))
		m_text.setFont(m_font);

    m_text.setCharacterSize(25);
}


void FPSCounter::update()
{
    m_frameCount++;

    if (m_delayTimer.getElapsedTime().asSeconds() > 0.2)
    {
        m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
        m_frameCount = 0;
        m_delayTimer.restart();
    }
}

void FPSCounter::draw(sf::RenderTarget& renderer)
{
    m_text.setString("FPS: " + std::to_string((int)m_fps));
    renderer.draw(m_text);
}
