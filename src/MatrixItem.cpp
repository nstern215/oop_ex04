#include "MatrixItem.h"

#include <iostream>

MatrixItem::MatrixItem(int row, int col, float positionOffsetX, float positionOffsetY) :
	m_row(row),
	m_col(col)
{
	setPosition(positionOffsetX, positionOffsetY);
}

MatrixItem::~MatrixItem() = default;

void MatrixItem::draw(sf::RenderWindow& window)
{
	m_square.draw(window);
}

void MatrixItem::setPosition(const sf::Vector2f& position)
{
	setPosition(position.x, position.y);
}

void MatrixItem::setPosition(float positionOffsetX, float positionOffsetY)
{
	m_square.setPosition({ m_col * m_square.getWidth() + positionOffsetX,
		m_row * m_square.getHeight() + positionOffsetY });
}

sf::Vector2f MatrixItem::getPosition() const
{
	return m_square.getPosition();
}


sf::FloatRect MatrixItem::getGlobalBound()
{
	return m_square.getGlobalBound();
}


void MatrixItem::onMouseClick(sf::Event& event, sf::Vector2f location)
{
	std::cout << "item " << m_row << ":" << m_col << " clicked" << std::endl;
}
