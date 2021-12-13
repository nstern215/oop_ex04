#include <iostream>

#include "BoardItem.h"
#include "Controller.h"

BoardItem::BoardItem(ItemInfo* itemInfo, int row, int col, float positionOffsetX, float positionOffsetY) :
	MatrixItem(itemInfo, row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
	std::string data = controller.getItemInfo()->m_itemData;

	if (m_itemInfo->m_itemData == " ")
	{
		if ((controller.getItemInfo()->m_itemData == "KING") || (controller.getItemInfo()->m_itemData == "THIEF") ||
			(controller.getItemInfo()->m_itemData == "WORRIER") || (controller.getItemInfo()->m_itemData == "MAGICIAN"))
		{
			if (!controller.appearence(controller.getItemInfo()))
			{
				controller.addCharacters(controller.getItemInfo()->m_itemData);
				setItem(controller.getItemInfo());
			}
		}
		else if (controller.getItemInfo()->m_itemData == "TELEPORT")
		{
			controller.addTeleport(m_col, m_row);
		}
		else
		{
				setItem(controller.getItemInfo());
		}
	}

	std::cout << "Board item " << m_row << ":" << m_col << " " << (m_itemInfo ? m_itemInfo->m_itemData : "") << " clicked" << std::endl;

}

void BoardItem::setItem(ItemInfo* itemInfo)
{
	m_itemInfo->m_itemData = itemInfo->m_itemData;

	m_square.setTexture(itemInfo->m_texture);
}

void BoardItem::clearItem(Controller*& controller)
{
	if ((m_itemInfo->m_itemData == "KING") || (m_itemInfo->m_itemData == "THIEF") ||
		(m_itemInfo->m_itemData == "MAGICIAN") || (m_itemInfo->m_itemData == "WORIER"))
	{
		controller->removeCharacter(controller->getItemInfo()->m_itemData);
	}
	else if (m_itemInfo->m_itemData == "TELEPORT")
	{
		controller->removeTeleport(m_row, m_col);
	}
	m_itemInfo->m_itemData = " ";
	m_itemInfo->m_texture = nullptr;
}

