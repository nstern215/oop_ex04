#pragma once

#include "Matrix.h"

class Menu : public Matrix {

public:
	Menu();
	~Menu();

	void resetAndResize(int row, int col);
	void init(Controller& controller);
};