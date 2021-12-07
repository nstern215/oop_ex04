#include "Square.h"

Square::Square(const float width, const float height, sf::Vector2f origin, sf::Vector2f position,
	sf::Texture* texture, sf::Color bgColor):
	m_width(width),
	m_height(height),
	m_origin(origin),
	m_position(position),
	m_texture(texture),
	m_bgColor(bgColor)
{}

void Square::draw(sf::RenderWindow& window)
{
	auto shape = sf::RectangleShape({ m_width, m_height });
	shape.setOrigin(m_origin);
	shape.setPosition(m_position);
	shape.setFillColor(m_bgColor);

	window.draw(shape);

	//todo: draw texture
}

void Square::setWidth(float width)
{
	m_width = width;
}

void Square::setHeight(float height)
{
	m_height = height;
}

void Square::setOrigin(sf::Vector2f origin)
{
	m_origin = origin;
}

void Square::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void Square::setTexture(sf::Texture* texture)
{
	m_texture = texture;
}

void Square::removeTexture()
{
	m_texture = nullptr;
}

sf::FloatRect Square::getGlobalBound()
{
	return sf::FloatRect(m_origin + m_position, { m_width, m_height });
}
