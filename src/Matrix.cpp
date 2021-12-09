#include "Matrix.h"

Matrix::Matrix(const unsigned int row, const unsigned int col):
    m_row(row),
    m_col(col)
{}

Matrix::~Matrix() = default;

void Matrix::draw(sf::RenderWindow& window)
{
	for (auto& v : m_items)
		for (auto*& item : v)
			item->draw(window);
}

void Matrix::setPosition(const sf::Vector2f& position)
{
	for (auto& v : m_items)
		for (auto* item : v)
			item->setPosition(position);
}

sf::FloatRect Matrix::getGlobalBound()
{
	auto topLeft = m_items[0][0]->getPosition();
	auto bottomRight= m_items[m_row - 1][m_col - 1]->getGlobalBound();

	auto bound = sf::FloatRect(topLeft, { bottomRight.left + bottomRight.width, bottomRight.top + bottomRight.height });
	
	return bound;
}

char Matrix::onMouseClick(sf::Event& event, sf::Vector2f location, char command)
{
	for (auto& v : m_items)
		for (auto* item : v)
			if (item->getGlobalBound().contains(location))
			{
				command = item->onMouseClick(event, location,command);
				return command;
			}
	return command;
}
