#pragma once

#include "MatrixItem.h"

class BoardItem : public MatrixItem
{
public:
	BoardItem(int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0);
	void onMouseClick(sf::Event& event, sf::Vector2f location);
};