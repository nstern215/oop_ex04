#pragma once

#include "MatrixItem.h"

#include <vector>

class MenuItem : public MatrixItem {

public:

	MenuItem(int col, float positionOffsetX, float positionOffsetY, ItemType type, sf::Texture* itemTexture, std::string itemData);

	void setInfo();

	virtual void onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData);


private:

};