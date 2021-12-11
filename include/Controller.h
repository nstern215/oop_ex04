#pragma once
#include "Board.h"
#include "Menu.h"
#include "MatrixItem.h"

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
	void takeAction(const ItemInfo& item);
	void addItem(const ItemInfo& item);
	void saveBoard();
	void clearBoard();

	sf::Texture* getTexture(std::string textureName);

	void setSelectedItem(ItemInfo& item);

private:
	void loadBoardFile();

	std::vector<sf::Vector2i> m_teleports;
	
	Menu m_menu;
	Board m_board;

	std::string m_selectedItemData;
	sf::Texture* m_selectedexture;

	std::vector<sf::Texture*> m_textures;
};

