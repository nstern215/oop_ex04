#pragma once

#include "Matrix.h"

class Board : public Matrix {

public:
	Board(const unsigned int col, const unsigned int row);
	~Board();

	void draw(sf::RenderWindow& window);
private:

};