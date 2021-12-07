#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"

class MatrixItem {

public:
	//todo:: is the origin require as ctor params?
    MatrixItem(int row = 0, int col = 0, float originX = 0, float originY = 0);
    virtual ~MatrixItem();
	
    virtual void draw(sf::RenderWindow& window);
    void setOrigin(const sf::Vector2f& origin);

protected:
    Square m_square;

    int m_row;
    int m_col;

private:
	
};