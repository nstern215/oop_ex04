#include "MenuItem.h"

#include <iostream>

MenuItem::MenuItem(int col, char display, float positionOffsetX, float positionOffsetY):
	MatrixItem(0, col, display, positionOffsetX, positionOffsetY)
{
	setDisplay();
}

void MenuItem::setDisplay()
{
	m_display = m_listDisplay[m_col];
}


char MenuItem::onMouseClick(sf::Event & event, sf::Vector2f location, char command)
{
std::cout << "Menu item " << m_row << ":" << m_col << " " << m_display << " clicked" << std::endl;

command = m_display;

return command;
}
