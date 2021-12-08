#include "Menu.h"

#include "MenuItem.h"

Menu::Menu(const unsigned col) :
	Matrix(1, col)
{
	m_items.emplace_back();
	for (int i = 0; i < m_col; i++)
		m_items[0].push_back(new MenuItem(i));
}

Menu::~Menu()
{
	//todo: check for memory leak
	for (auto& v : m_items)
		for (auto*& item : v)
			delete item;
}
