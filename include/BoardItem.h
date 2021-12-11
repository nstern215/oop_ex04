#pragma once

#include "MatrixItem.h"
#include <vector>

class BoardItem : public MatrixItem
{
public:
	BoardItem(int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0, sf::Texture* itemTexture, std::string itemData);

	void onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData);

	void setItem(sf::Texture* itemTexture, const std::string& info);

	void clearItem();

	void addItem(sf::Texture* itemTexture, const std::string& info);

	bool appearence(const std::string& info);

private:
	
	std::vector<BoardItem> m_characters;

	bool m_boarded;
};