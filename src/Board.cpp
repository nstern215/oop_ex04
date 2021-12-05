#include "Board.h"

#include <iostream>

Board::Board(const unsigned int row, const unsigned int col, const int positionX, const int positionY) :
	m_row(row),
	m_col(col),
	m_positionX(positionX),
	m_positionY(positionY)
{
	initBoard();
}

Square Board::getElem(const unsigned row, const unsigned col)
{
	//todo: validate location
	return m_data[row][col];
}

void Board::initBoard()
{
	for (int i = 0; i < m_row; i++)
	{
		m_data.emplace_back();

		for (int j = 0; j < m_col; j++)
			m_data[i].emplace_back(i, j, m_positionX, m_positionY);
	}
}

void Board::draw(sf::RenderWindow& window/*, const float positionX, const float positionY*/)
{
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
			m_data[i][j].draw(window);
}

sf::FloatRect Board::getGlobalBound()
{
	sf::Vector2f topLeft = m_data[0][0].getPosition();
	Square& bottomRightSquare = m_data[m_row - 1][m_col - 1];
	sf::Vector2f bottomRightPosition = bottomRightSquare.getPosition();
	sf::Vector2f bottomRight(bottomRightPosition.x + bottomRightSquare.getWidth(),
		bottomRightPosition.y + bottomRightSquare.getHeigth());

	return sf::FloatRect(topLeft, bottomRight);
}

void Board::mouseButtonReleased(sf::Event& evt, sf::RenderWindow& window)
{
	for (int i = 0; i < m_row; i++)
		for (auto& square : m_data[i])
			if (square.getGlobalBound().contains(window.mapPixelToCoords({evt.mouseButton.x, evt.mouseButton.y})))
			{
				square.mouseButtonReleased(evt, window);
				return;
			}
}

void Board::mouseMoved(sf::Event& evt, sf::RenderWindow& window)
{
	for (int i = 0; i < m_row; i++)
		for (auto& square : m_data[i])
			if (square.getGlobalBound().contains(window.mapPixelToCoords({ evt.mouseMove.x, evt.mouseMove.y })))
			{
				square.mouseMoved(evt, window);
				return;
			}
}
