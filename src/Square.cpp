#include "Square.h"

Square::Square(const float width, const float height, sf::Vector2f position,
	sf::Texture* texture, sf::Color bgColor):
	m_width(width),
	m_height(height),
	m_position(position),
	m_texture(texture),
	m_bgColor(bgColor)
{}

Square::Square(const Square& other)
{
	//todo: test if work
	*this = other;
	
	/*m_width = other.getWidth();
	m_height = other.getHeight();
	m_position = other.getPosition();
	m_texture = other.getTexture();
	m_bgColor = other.getBgColor();*/
}


Square& Square::operator=(const Square& other)
{
	if (this != &other)
	{
		m_width = other.getWidth();
		m_height = other.getHeight();
		m_position = other.getPosition();
		m_texture = other.getTexture();
		m_bgColor = other.getBgColor();
	}

	return *this;
}


void Square::draw(sf::RenderWindow& window)
{
	auto shape = sf::RectangleShape({ m_width, m_height });
	
	shape.setPosition(m_position);
	shape.setFillColor(m_bgColor);

	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1);

	window.draw(shape);

	//todo: draw texture

	auto shapeT = sf::RectangleShape({ m_width, m_height });

	sf::Texture texture;
	texture.loadFromFile("crown.png");

	shapeT.setPosition(m_position);
	shapeT.setFillColor(m_bgColor);

	shapeT.setOutlineColor(sf::Color::Black);
	shapeT.setOutlineThickness(1);

	shapeT.setTexture(&texture, true);

	window.draw(shapeT);
}

void Square::setWidth(float width)
{
	m_width = width;
}

void Square::setHeight(float height)
{
	m_height = height;
}

float Square::getWidth() const
{
	return m_width;
}

float Square::getHeight() const
{
	return m_height;
}

void Square::setPosition(const sf::Vector2f& position)
{
	m_position = position;
}

sf::Vector2f Square::getPosition() const
{
	return m_position;
}

void Square::setTexture(sf::Texture* texture)
{
	m_texture = texture;
}

void Square::removeTexture()
{
	m_texture = nullptr;
}

sf::FloatRect Square::getGlobalBound() const
{
	return sf::FloatRect(m_position, { m_width, m_height });
}

sf::Color Square::getBgColor() const
{
	return m_bgColor;
}

void Square::setBgColor(sf::Color color)
{
	m_bgColor = color;
}

sf::Texture* Square::getTexture() const
{
	return m_texture;
}
