#pragma once

#include <vector>
#include "Matrix.h"

#define DEFAULT_ROW 10
#define DEFAULT_COL 10

class Board : public Matrix {

public:
	Board(unsigned int row = DEFAULT_ROW, unsigned int col = DEFAULT_COL, Controller* controller);
	~Board();

	void draw(sf::RenderWindow& window);
};