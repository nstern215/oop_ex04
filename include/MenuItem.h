#pragma once

#include "MatrixItem.h"

#include <vector>

enum ItemType
{
	ACTION = 0,
	ELEMENT = 1
};

class MenuItem : public MatrixItem {

public:

	MenuItem(ItemInfo* itemInfo, int col, float positionOffsetX, float positionOffsetY);

	virtual void onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller);


private:

};