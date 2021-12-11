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
	Controller();
	void run();

	sf::Texture* getTexture(TextureIndex textureName);

private:
	void loadBoardFile();

	std::vector<sf::Vector2i> m_teleports;
	
	Menu m_menu;
	Board m_board;

	std::vector<sf::Texture*> m_textures;
};

