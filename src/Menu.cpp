#include "Menu.h"

#include "MenuItem.h"

Menu::Menu(const unsigned int col):
	Matrix(1, col)
{
	m_items.emplace_back();

	std::vector<std::string> elems = { "KING", "WORIER", "THIEF", "MAGICIAN", "WALL", "TELEPORT", "KEY", "GATE", "FIRE", "ORK" };
	std::vector<std::string> actions = { "ADD", "DELETE", "CLEAR", "SAVE" };

	int Counter = 0; 

	//int elemCounter = 0;

	//int actionItem = 0;

	for (auto& elem : elems)
	{
		m_items[0].push_back(new MenuItem(Counter++, 0, 0, ELEMENT, m_controller->getTexture(elem), elem));
	}

	for (auto& action : actions)
	{
		m_items[0].push_back(new MenuItem(Counter++, 0, 0, ACTION, m_controller.getTexture(action), action);
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
