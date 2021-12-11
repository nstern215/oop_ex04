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
	void takeAction(const ItemInfo& item);
	void addItem(const ItemInfo& item);
	void deleteItem(ItemInfo item);
	void saveBoard();
	void clearBoard();

	/*sf::Texture* getTexture(std::string name);*/

private:

	Menu m_menu;
	Board m_board;

	ItemInfo m_itemInfo;
};
