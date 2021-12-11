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

	MenuItem(int col, float positionOffsetX, float positionOffsetY, ItemType type, sf::Texture* itemTexture, std::string itemData);

	void setInfo();

	virtual void onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, sf::Texture* itemTexture = nullptr, std::string itemData = " ");


private:

};