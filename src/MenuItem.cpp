#include "MenuItem.h"

#include <iostream>


MenuItem::MenuItem(int col, float positionOffsetX, float positionOffsetY, ItemInfo itemInfo) :
	MatrixItem(0, col, positionOffsetX, positionOffsetY)
{
	m_itemInfo.m_itemData = itemInfo.m_itemData;
	m_itemInfo.m_texture = itemInfo.m_texture;
}


void MenuItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, const int& mode, ItemInfo itemInfo)
{
	std::cout << "Menu item " << m_row << ":" << m_col << " " << m_itemInfo.m_itemData <<
																		" clicked" << std::endl;

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
