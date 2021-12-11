#include "MenuItem.h"

#include <iostream>

enum ItemType {
	ACTION = 0,
ELEMENT = 1
};

MenuItem::MenuItem(int col, float positionOffsetX, float positionOffsetY, ItemType type, sf::Texture* itemTexture, std::string itemData):
	MatrixItem(0, col, positionOffsetX, positionOffsetY)
{
}


void MenuItem::onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData)
{
 std::cout << "Menu item " << m_row << ":" << m_col << " " << m_itemInfo.m_info << " clicked" << std::endl;

 switch (m_itemInfo.m_type)
 {
 case 0:
	 m_controller->takeAction();
	 break;
 case 1:
	 m_controller->setSelectedItem(m_itemInfo);
	 break;
 }
}
