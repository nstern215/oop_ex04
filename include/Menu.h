#pragma once

#include "Matrix.h"

class Menu : public Matrix {

public:
	Menu(const unsigned int col = 0);
	~Menu();

	void resetAndResize(int row, int col);
private:
	
};