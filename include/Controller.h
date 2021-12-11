#pragma once
#include "Board.h"
#include "Menu.h"
#include "MatrixItem.h"

//struct ItemInfo;

class Controller
{
public:
	//todo: load board\get dimensions for a new board
	
	Controller();
	void run();
	void addItem();
	void deleteItem();
	void saveBoard();
	void clearBoard();
	void setSelectedItem();

	sf::Texture* getTexture(std::string name);

private:

	Menu m_menu;
	Board m_board;

	ItemInfo m_itemInfo;
};
