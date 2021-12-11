#pragma once

#include "MatrixItem.h"
#include <vector>

class BoardItem : public MatrixItem
{
public:
	BoardItem(int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0);

	void onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData);

	void relocate(BoardItem character);

	void clearItem();

	void addItem(const std::string& info);

	bool appearence(const std::string& info);

private:
	
	std::vector<BoardItem> m_characters;

	bool m_boarded;
};