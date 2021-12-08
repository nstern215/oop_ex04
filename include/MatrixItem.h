#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"

class MatrixItem {

public:
    MatrixItem(int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0);
    virtual ~MatrixItem();
	
    virtual void draw(sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float positionOffsetX, float positionOffsetY);
    sf::Vector2f getPosition() const;
	
    sf::FloatRect getGlobalBound();
	
    virtual void onMouseClick(sf::Event& event, sf::Vector2f location);

protected:
	
    Square m_square;

    int m_row;
    int m_col;
};