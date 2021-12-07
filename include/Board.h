#pragma once

#include <vector>
#include "Matrix.h"


class Board : public Matrix {

public:
	Board(const unsigned int col, const unsigned int row);
	~Board();

	void draw(sf::RenderWindow& window);

protected:

	std::vector<MatrixItem> m_charactersLIst;

	std::vector<MatrixItem> m_tilesLIst;

private:



};