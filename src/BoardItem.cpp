#include "BoardItem.h"

#include <iostream>

BoardItem::BoardItem(int row, int col, float positionOffsetX, float positionOffsetY):
	MatrixItem(row, col, positionOffsetX, positionOffsetY)
{}

void BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData)
{
	std::cout << "Board item " << m_row << ":" << m_col << " " << m_itemInfo.m_info << " clicked" << std::endl;
}

void BoardItem::relocate(BoardItem character)
{
	character.setPosition(m_square.getPosition());
}

void BoardItem::clearItem()
{
	m_itemInfo.m_info = " ";
}

void BoardItem::addItem(const std::string& info)
{
	BoardItem character(m_row, m_col, m_square.getPosition().x, m_square.getPosition().y);

	m_characters.push_back(character);
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

