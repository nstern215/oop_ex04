#include <iostream>

#include "BoardItem.h"
#include "Controller.h"

BoardItem::BoardItem(ItemInfo* itemInfo, int row, int col, float positionOffsetX, float positionOffsetY) :
	MatrixItem(itemInfo, row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
	std::string data = controller.getItemInfo()->m_itemData;

		if ((data == "KING") || (data == "THIEF") || (data == "WARRIOR") ||
			(data == "MAGE") || (data == "THRONE")|| (data == " "))
		{
				if ((!controller.appearence(data)) && (controller.getMode() == 0) && (m_itemInfo->m_itemData == " "))
				{
					controller.addCharacters(controller.getItemInfo()->m_itemData);
					setItem(controller.getItemInfo());
				}
				else if ((controller.appearence(m_itemInfo->m_itemData)) && (controller.getMode() != 0) && (m_itemInfo->m_itemData != " "))
				{
					controller.removeCharacter(m_itemInfo->m_itemData);
					setItem(controller.getItemInfo());
				}
		}

		if ((data == "TELEPORT") || (data == " "))
		{
			if (data == " ")
			{
				controller.removeTeleport(m_col, m_row);
				setItem(controller.getItemInfo());
			}
			else if((m_itemInfo->m_itemData == " ") || (controller.getMode() != 0))
			{
				controller.addTeleport(m_col, m_row);
				setItem(controller.getItemInfo());
			}
		}

		if((data == "ORK") || (data == "WALL") || (data == "FIRE") || (data == "KEY") || (data == "GATE") || (data == " "))
		{
			if ((m_itemInfo->m_itemData == " ") || (controller.getMode() != 0))
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

