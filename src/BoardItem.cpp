#include "BoardItem.h"

#include <iostream>

BoardItem::BoardItem(int row, int col, char display, float positionOffsetX, float positionOffsetY):
	MatrixItem(row, col, display, positionOffsetX, positionOffsetY)
{}

void BoardItem::setDisplay(const char& display)
{
	m_display = display;
}

char BoardItem::onMouseClick(sf::Event& event, sf::Vector2f location, char command)
{
	if ((command == 'K')||(command == 'T')||(command == 'W')||(command == 'M')||(command == '@'))
	{
		if (appearence(command))
		{
			addItem(command);
		}
	}
	else if((command == '=')||(command == '#')||(command == 'F')||(command == '!')||(command == '*'))
	{
		m_display = command;
	}
	else
    {
		clearItem();
    }
	m_display = command;

	std::cout << "Board item " << m_row << ":" << m_col << " " << m_display << " clicked" << std::endl;

	command = ' ';

	return command;
}

void BoardItem::relocate(BoardItem character)
{
	character.setPosition(m_square.getPosition());
}

void BoardItem::clearItem()
{
	m_display = ' ';
}

void BoardItem::addItem(const char& command)
{
	BoardItem character(m_row, m_col, command, m_square.getPosition().x, m_square.getPosition().y);

	m_characters.push_back(character);
}

bool BoardItem::appearence(const char& command)
{
	for (int i = 0; i < m_characters.size(); i++)
	{
		if (m_characters[i].m_display == command)
		{
			relocate(m_characters[i]);
			m_boarded = true;
			break;
		}
	}
	return m_boarded;
}

