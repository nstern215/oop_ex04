#include "Menu.h"

#include "MenuItem.h"

Menu::Menu(const unsigned int col) :
	Matrix(1, col)
{
	m_items.emplace_back();

	std::vector elems = {"KING", "WORIER", "THIEF", "MAGICIAN", "WALL", "TELEPORT", "KEY", "GATE", "FIRE", "ORK"}
	std::vector actions = {"ADD", "DELETE", "CLEAR", "SAVE"}

	int elemsCounter = 0; 

	for (auto& elem : elems)
	{
		m_items[0].push_back(new MenuItem(counter++, " ", 0, 0, elem, m_controller.getTexture(elem), ELEMENT);
	}

	int actionsCoounter = 0;

	for (auto& action : actions)
	{
		m_items[0].push_back(new MenuItem(counter++, " ", 0, 0, action, m_controller.getTexture(action), ACTION);
	}
}

Menu::~Menu()
{
	//todo: check for memory leak
	for (auto& v : m_items)
		for (auto*& item : v)
			delete item;
}
