#pragma once

#include "MatrixItem.h"
#include <vector>

class King;

class BoardItem : public MatrixItem
{
public:
	
	BoardItem(int row = 0, int col = 0, char display = ' ', float positionOffsetX = 0, float positionOffsetY = 0);
	
	void setDisplay(const char&);

	char onMouseClick(sf::Event& event, sf::Vector2f location, char command);

	void relocate(BoardItem character);

	void clearItem();

	void addItem(const char& command);

	bool appearence(const char& command);

private:
	
	std::vector<BoardItem> m_characters;

	bool m_boarded;
};