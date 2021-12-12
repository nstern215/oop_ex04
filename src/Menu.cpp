#include "Menu.h"

#include "MenuItem.h"
#include "Controller.h"

Menu::Menu():
	Matrix(1)
{}

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

void Menu::init(Controller& controller)
{	
	m_items.emplace_back();

	std::vector<std::string> elems = { "KING", "WORIER", "THIEF", "MAGICIAN", "WALL", "TELEPORT", "KEY", "GATE", "FIRE", "ORK" };
	std::vector<std::string> actions = { "ADD", "DELETE", "CLEAR", "SAVE" };

	int counter = 0;

	for (auto& elem : elems)
	{
		ItemInfo* info = new ItemInfo();
		info->m_texture = controller.getTexture(elem);
		info->m_itemData = elem;

		m_items[0].push_back(new MenuItem(info, counter++, 0, 0));
	}

	for (auto& action : actions)
	{
		ItemInfo* info = new ItemInfo();
		info->m_texture = controller.getTexture(actions);
		info->m_itemData = action;

		m_items[0].push_back(new MenuItem(info, counter++, 0, 0));
	}
}