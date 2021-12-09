#pragma once
#include "Board.h"
#include "Menu.h"

class Controller
{
public:
	//todo: load board\get dimensions for a new board
	
	Controller();
	void run();



private:
	Menu m_menu;
	Board m_board;

	char m_command;
};
