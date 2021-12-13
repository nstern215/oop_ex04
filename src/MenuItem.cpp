#include <iostream>

#include "MenuItem.h"
#include "Controller.h"

MenuItem::MenuItem(ItemInfo* itemInfo, int col, float positionOffsetX, float positionOffsetY) :
	MatrixItem(itemInfo, 0, col, positionOffsetX, positionOffsetY)
{
	m_itemInfo->m_itemData = itemInfo->m_itemData;
	m_itemInfo->m_texture = itemInfo->m_texture;
}


void MenuItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
	std::cout << "Menu item " << m_row << ":" << m_col << " " << m_itemInfo->m_itemData <<
																		" clicked" << std::endl;

	std::string command = m_itemInfo->m_itemData;

	switch (m_itemInfo->m_type)
	{
	case 0:
		controller.takeAction(command);
		break;
	case 1:
		controller.setSelectedItem(m_itemInfo);
		break;
	}
}
