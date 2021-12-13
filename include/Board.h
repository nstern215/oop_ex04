#pragma once

#include <vector>
#include "Matrix.h"

class Controller;

#define DEFAULT_ROW 10
#define DEFAULT_COL 10

class Board : public Matrix {

public:
	Board(unsigned int row = DEFAULT_ROW, unsigned int col = DEFAULT_COL);
	~Board();

	void draw(sf::RenderWindow& window);
	void load(std::vector<std::string> content);

	std::vector<std::string> save(Controller& controller);

protected:
	void initMatrix();
	void freeMemory();
};