#include <iostream>

#include "BoardItem.h"
#include "Controller.h"

BoardItem::BoardItem(ItemInfo* itemInfo, int row, int col, float positionOffsetX, float positionOffsetY) :
	MatrixItem(itemInfo, row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
	std::cout << "Board item " << m_row << ":" << m_col << " " << (m_itemInfo ? m_itemInfo->m_itemData : "") << " clicked" << std::endl;

	std::string data = controller.getItemInfo()->m_itemData;

	if (((controller.getItemInfo()->m_itemData == "KING") ||
		(controller.getItemInfo()->m_itemData == "THIEF") ||
		(controller.getItemInfo()->m_itemData == "WORIER") ||
		(controller.getItemInfo()->m_itemData == "MAGICIAN")) && (m_itemInfo->m_itemData == " "))
	{
		if (!appearence(controller.getItemInfo()))
		{
			addCharacter(controller.getItemInfo());
			setItem(controller.getItemInfo());
		}
	}
	else if (controller.getItemInfo()->m_itemData == "TELEPORT")
	{
		controller.addTeleport(m_col, m_row);
	}
	else
	{
		if (m_itemInfo->m_itemData == " ")
		{
			setItem(controller.getItemInfo());
		}
	}
}

void BoardItem::setItem(ItemInfo* itemInfo)
{
	m_itemInfo->m_itemData = itemInfo->m_itemData;

	m_itemInfo->m_texture = itemInfo->m_texture;
}

void BoardItem::clearItem(Controller*& controller)
{
	if ((m_itemInfo->m_itemData == "KING") || (m_itemInfo->m_itemData == "THIEF") ||
		(m_itemInfo->m_itemData == "MAGICIAN") || (m_itemInfo->m_itemData == "WORIER"))
	{
		for (int i = 0; i < m_characters.size(); i++)
		{
			if (m_characters[i] == m_itemInfo->m_itemData)
			{
				m_characters.erase(m_characters.begin() - i);
			}
		}
	}
	else if (m_itemInfo->m_itemData == "TELEPORT")
	{
		controller->removeTeleport(m_row, m_col);
	}
	m_itemInfo->m_itemData = " ";
	m_itemInfo->m_texture = nullptr;
}


void BoardItem::addCharacter(ItemInfo* itemInfo)
{
	m_characters.push_back(itemInfo->m_itemData);
}

bool BoardItem::appearence(ItemInfo* itemInfo)
{
	for (int i = 0; i < m_characters.size(); i++)
	{
		if (m_characters[i] == itemInfo->m_itemData)
		{
			m_boarded = true;
			break;
		}
	}
	return m_boarded;
}

