#pragma once

#include "Matrix.h"

#define DEFAULT_ROW 10
#define DEFAULT_COL 10

class Board : public Matrix {

public:
	Board(unsigned int col = DEFAULT_ROW, unsigned int row = DEFAULT_COL);
	~Board();

	void draw(sf::RenderWindow& window);
private:

};