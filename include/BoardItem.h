#pragma once

#include "MatrixItem.h"

class BoardItem : public MatrixItem
{
public:
	BoardItem(int row = 0, int col = 0, float originX = 0, float originY = 0);
};