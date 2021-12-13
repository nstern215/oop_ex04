#pragma once

#include "MatrixItem.h"
#include <vector>

class BoardItem : public MatrixItem
{
public:
	BoardItem(ItemInfo* itemInfo = nullptr, int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0);

	void onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller);

	void setItem(ItemInfo* itemInfo);

	void clearItem(Controller*& controller);

	bool appearence(ItemInfo* itemInfo);

private:
	
};