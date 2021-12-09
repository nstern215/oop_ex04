#include "MatrixItem.h"

#include <iostream>

MatrixItem::MatrixItem(int row, int col, char display ,float positionOffsetX, float positionOffsetY) :
	m_row(row),
	m_col(col),
	m_display(display)
{
	setPosition(positionOffsetX, positionOffsetY);
}

//todo: delete as MatrixItem
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

char MatrixItem::getDsiplay() const
{
	return m_display;
}

void MatrixItem::setDisplay(char display)
{
	m_display = display;
}

char MatrixItem::onMouseClick(sf::Event& event, sf::Vector2f location, char command)
{
	std::cout << "item " << m_row << ":" << m_col << m_display << " clicked" << std::endl;

	return command;
}
