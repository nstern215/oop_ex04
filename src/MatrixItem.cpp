#include "MatrixItem.h"

MatrixItem::MatrixItem(int row, int col, float originX, float originY) :
	m_col(col),
	m_row(row)
{
	m_square.setOrigin({ originX, originY });
	m_square.setPosition({ m_col * m_square.getWidth(), m_row * m_square.getHeight() });
}

void MatrixItem::draw(sf::RenderWindow& window)
{
	m_square.draw(window);
}

void MatrixItem::setOrigin(const sf::Vector2f& origin)
{
	m_square.setOrigin(origin);
}
