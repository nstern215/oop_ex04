#include "BoardItem.h"

#include <iostream>

BoardItem::BoardItem(int row, int col, float positionOffsetX, float positionOffsetY):
	MatrixItem(row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location)
{
	std::cout << "Board item " << m_row << ":" << m_col << " clicked" << std::endl;
}
