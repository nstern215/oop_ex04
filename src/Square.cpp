#include "Square.h";

#include <iostream>
#include <SFML/Graphics.hpp>

#define OUTLINE_THIKNESS 1;

Square::Square(int row, int col, const int positionOffsetX, const int positionOffsetY, float width, float height, sf::Color color) :
	m_row(row),
	m_col(col),
	m_width(width),
	m_height(height),
	m_position(col* width + positionOffsetX, row* height + positionOffsetY),
	m_color(color)
{}

void Square::draw(sf::RenderWindow& window) const
{
	auto shape = sf::RectangleShape({ m_width, m_height });
	shape.setPosition(m_position);
	shape.setFillColor(m_color);

	shape.setOutlineColor(sf::Color::Blue);
	shape.setOutlineThickness(1);

	window.draw(shape);

	sf::Texture crown;
	crown.loadFromFile("crown.png");
	sf::Sprite crownSprite(crown);

	crownSprite.setPosition(m_position);

	window.draw(crownSprite);
}

sf::Vector2f Square::getPosition() const
{
	return m_position;
}

float Square::getWidth() const
{
	return m_width;
}

float Square::getHeigth() const
{
	return m_height;
}

sf::FloatRect Square::getGlobalBound()
{
	return sf::FloatRect(m_position, { m_width, m_height });
}

void Square::mouseButtonReleased(sf::Event& evt, sf::RenderWindow& window)
{
	std::cout << "square " << m_row << ":" << m_col << " clicked" << std::endl;
}

void Square::mouseMoved(sf::Event& evt, sf::RenderWindow& window)
{
	m_color = sf::Color::Red;
}
