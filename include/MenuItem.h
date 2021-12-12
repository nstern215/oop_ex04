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

	MenuItem(ItemInfo itemInfo, int col, float positionOffsetX, float positionOffsetY, ItemInfo itemInfo);

	virtual void onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, const int& mode, ItemInfo itemInfo);


private:

};