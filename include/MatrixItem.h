#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"

class MatrixItem {

public:
    MatrixItem();

    virtual void draw(sf::RenderWindow& window);

protected:
    Square m_square;

private:

};