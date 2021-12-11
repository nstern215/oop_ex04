#pragma once
#include "Board.h"
#include "Menu.h"

enum TextureIndex
{
	CROWN = 0,
	FIRE = 1,
	GATE = 2,
	ORK = 3,
	THIEF = 4,
	WARRIOR = 5,
	TELEPORT = 6,
	THRONE = 7,
	DELETE = 8,
	OPEN = 9,
	SAVE = 10
};

class Controller
{
public:
	//todo: load board\get dimensions for a new board
	
	Controller();
	void run();

	sf::Texture* getTexture(TextureIndex textureName);

private:
	Menu m_menu;
	Board m_board;

	std::vector<sf::Texture*> m_textures;
};

