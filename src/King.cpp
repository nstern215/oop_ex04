#include "..\include\King.h"

void King::onMouseClick(sf::Event& event, sf::Vector2f location)
{
	std::cout << "King " << m_row << ":" << m_col << " clicked" << std::endl;

	if (!m_boarded)
	{

	}
	else
	{
		std::cout << "King already placed on board"<< std::endl;
	}

}

bool King::kingAtThron()
{
	m_thron = true;

	return m_thron;
}
