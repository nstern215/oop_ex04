#include "MenuItem.h"

#include <iostream>


MenuItem::MenuItem(int col, float positionOffsetX, float positionOffsetY, ItemType type, sf::Texture* itemTexture, std::string itemData) :
	MatrixItem(0, col, positionOffsetX, positionOffsetY)
{
	m_itemInfo.m_itemData = itemData;
	m_itemInfo.m_texture = itemTexture;
}


void MenuItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, sf::Texture* itemTexture, std::string itemData)
{
	std::cout << "Menu item " << m_row << ":" << m_col << " " << m_itemInfo.m_itemData << " clicked" << std::endl;

	switch (m_itemInfo.m_type)
	{
	case 0:
		controller.takeAction(m_itemInfo);
		break;
	case 1:
		controller.setSelectedItem(m_itemInfo);
		break;
	}
}
