#include "BoardItem.h"

#include <iostream>

BoardItem::BoardItem(int row, int col, float positionOffsetX, float positionOffsetY, sf::Texture* itemTexture, std::string itemData):
	MatrixItem(row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData)
{
	std::cout << "Board item " << m_row << ":" << m_col << " " << m_itemInfo.m_info << " clicked" << std::endl;

	if (((itemData.m_itemData() == "KING") ||
		(itemData.m_itemData() == "THIEF") ||
		(itemData.m_itemData() == "WORIER") ||
		(itemData.m_itemData() == "MAGICIAN")) && (m_itemInfo.m_itemData == " "))
	{
		if(!appearence(itemTexture, itemInfo))
		{
			addCharacter(itemTexture, itemData)
				setItem(itemTexture, itemData);
		}
	}
	else if (itemData.m_itemData() == "TELEPORT")
	{
		if (m_itemInfo.m_itemData == " ")
		{
			setItem(itemTexture, itemData)
		}
	}
	else
	{
		if (m_itemInfo.m_itemData == " ")
		{
			setItem(itemTexture, itemData)
		}
	}
}

void BoardItem::setItem(sf::Texture* itemTexture, const std::string& info)
{
	m_itemInfo.m_itemData = info;

	m_itemInfo.m_texture = itemTexture;
}

void BoardItem::clearItem()
{
	m_itemInfo.m_info = " ";
}


void BoardItem::addCharacter(sf::Texture* itemTexture, const std::string& info)
{
	BoardItem character(m_row, m_col, m_square.getPosition().x, m_square.getPosition().y,itemTexture, info);

	m_characters.push_back(character);
}

void BoardItem::addTeleport(sf::Texture* itemTexture, const std::string& info)
{
	BoardItem teleport(m_row, m_col, m_square.getPosition().x, m_square.getPosition().y, itemTexture, info);

	m_characters.push_back(teleport);
}

bool BoardItem::appearence(const std::string& info)
{
	for (int i = 0; i < m_characters.size(); i++)
	{
		if (m_characters[i].m_itemInfo.m_info == info)
{
			relocate(m_characters[i]);
			m_boarded = true;
			break;
		}
	}
	return m_boarded;
}

