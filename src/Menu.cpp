#include "Menu.h"

#include "MenuItem.h"

enum Type
{
	ACTION = 0;
ELEMENT = 1;

};

Menu::Menu(const unsigned int col, Controller* controller) :
	Matrix(1, col, controller)
{
	m_items.emplace_back();

	std::vector elems = { "KING", "WORIER", "THIEF", "MAGICIAN", "WALL", "TELEPORT", "KEY", "GATE", "FIRE", "ORK" };
	std::vector actions = { "ADD", "DELETE", "CLEAR", "SAVE" };

	int elemsCounter = 0; 

	for (auto& elem : elems)
	{
		m_items[0].push_back(new MenuItem(elemsCounter++, 0, 0, ELEMENT, m_controller->getTexture(elem), elem));
		/*m_items[0].push_back(new MenuItem(elemsCounter++, " ", 0, 0, elem, m_controller.getTexture(elem));*/
	}

	int actionsCoounter = 0;

	for (auto& action : actions)
	{
		m_items[0].push_back(new MenuItem(counter++, " ", 0, 0, action, m_controller.getTexture(action), ACTION);
	}
}

Menu::~Menu()
{
	for (auto& v : m_items)
		for (auto*& item : v)
		{
			delete item;
			item = nullptr;
		}
}

void Menu::resetAndResize(int row, int col)
{}
