#pragma once

#include "Location.h"
#include <SFML/Graphics.hpp>

#define DEFAULT_SQUARE_WIDTH 50
#define DEFAULT_SQUARE_HEIGHT 50

class Square
{
public:
	Square(int row = 0, int col = 0, const int positionOffsetX = 0, const int positionOffsetY = 0,
		float width = DEFAULT_SQUARE_WIDTH, float height = DEFAULT_SQUARE_HEIGHT, sf::Color color = sf::Color::White);

	void draw(sf::RenderWindow& window) const;
	

	sf::Vector2f getPosition() const;
	float getWidth() const;
	float getHeigth() const;

	sf::FloatRect getGlobalBound();
	void mouseButtonReleased(sf::Event& evt, sf::RenderWindow& window);
	void mouseMoved(sf::Event& evt, sf::RenderWindow& window);

private:
	int m_row;
	int m_col;
	float m_width;
	float m_height;

	sf::Vector2f m_position;
	sf::Color m_color;
};
