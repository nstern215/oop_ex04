#include "BoardItem.h"

#include <iostream>

BoardItem::BoardItem(ItemInfo itemInfo, int row, int col, float positionOffsetX, float positionOffsetY):
	MatrixItem(row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, const int& mode, ItemInfo itemInfo)
{
	std::cout << "Board item " << m_row << ":" << m_col << " " << m_itemInfo.m_itemData << " clicked" << std::endl;

	if (mode == 0)
	{
		if (((itemInfo.m_itemData == "KING") ||
			(itemInfo.m_itemData == "THIEF") ||
			(itemInfo.m_itemData == "WORIER") ||
			(itemInfo.m_itemData == "MAGICIAN")) && (m_itemInfo.m_itemData == " "))
		{
			if (!appearence(itemInfo))
			{
				addCharacter(itemInfo);
				setItem(itemInfo);
			}
		}
		else if (itemInfo.m_itemData == "TELEPORT")
		{
			controller.addTeleport(m_col, m_row);
		}
		else
		{
			if (m_itemInfo.m_itemData == " ")
			{
				setItem(itemInfo);
			}
		}
	}
	else
	{
		clearItem(controller);
	}
	
}

void BoardItem::setItem(ItemInfo itemInfo)
{
	m_itemInfo.m_itemData = itemInfo.m_itemData;

	m_itemInfo.m_texture = itemInfo.m_texture;
}

void BoardItem::clearItem(Controller controller)
{
	if ((m_itemInfo.m_itemData == "KING") || (m_itemInfo.m_itemData == "THIEF") ||
		(m_itemInfo.m_itemData == "MAGICIAN") || (m_itemInfo.m_itemData == "WORIER"))
	{
		for (int i = 0; i < m_characters.size(); i++)
		{
			if (m_characters[i].m_itemInfo.m_itemData == m_itemInfo.m_itemData)
			{
				m_characters.erase(m_characters.begin() - i);
			}
		}
	}
	else if (m_itemInfo.m_itemData == "TELEPORT")
	{
		controller.removeTeleport(m_row, m_col);
	}
	m_itemInfo.m_itemData = " ";
	m_itemInfo.m_texture = nullptr;
}


void BoardItem::addCharacter(ItemInfo itemInfo)
{
	BoardItem character(itemInfo, m_row, m_col, m_square.getPosition().x, m_square.getPosition().y);

	m_characters.push_back(character);
}

//void BoardItem::addTeleport(ItemInfo itemInfo)
//{
//	BoardItem teleport(itemInfo, m_row, m_col, m_square.getPosition().x, m_square.getPosition().y);
//
//	m_characters.push_back(teleport);
//}

bool BoardItem::appearence(ItemInfo itemInfo)
{
	for (int i = 0; i < m_characters.size(); i++)
	{
		if (m_characters[i].m_itemInfo.m_itemData == itemInfo.m_itemData)
		{
			m_boarded = true;
			break;
		}
	}
	return m_boarded;
}

