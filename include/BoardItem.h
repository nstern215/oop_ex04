#pragma once

#include "MatrixItem.h"
#include <vector>

class BoardItem : public MatrixItem
{
public:
	BoardItem(ItemInfo itemInfo, int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0);

	void onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, const int& mode, ItemInfo itemInfo);

	void setItem(ItemInfo itemInfo);

	void clearItem(Controller controller);

	void addCharacter(ItemInfo itemInfo);

	/*void addTeleport(ItemInfo itemInfo);*/

	bool appearence(ItemInfo itemInfo);

private:
	
	std::vector<BoardItem> m_characters;

	bool m_boarded;
};