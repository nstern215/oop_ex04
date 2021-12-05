#pragma once

#include <vector>

#include "Square.h";

class Board
{
public:
	Board(const unsigned int row = 0, const unsigned int col = 0, const int positionX = 0, const int positionY = 0);
	Square getElem(const unsigned int row, const unsigned int col);

	void draw(sf::RenderWindow& window/*, const float positionX, const float positionY*/);
	sf::FloatRect getGlobalBound();

	void mouseButtonReleased(sf::Event& evt, sf::RenderWindow& window);
	void mouseMoved(sf::Event& evt, sf::RenderWindow& window);

private:
	void initBoard();
	
	unsigned int m_row;
	unsigned int m_col;
	int m_positionX;
	int m_positionY;
	std::vector<std::vector<Square>> m_data;
};
