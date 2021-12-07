#include "Menu.h"

Menu::Menu(const unsigned col):
	Matrix(1, col)
{}

Menu::~Menu()
{
	//todo: check for memory leak
	for (auto& v : m_items)
		for (auto*& item : v)
			delete item;
}
