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
	SAVE = 10,
	ADD = 11,
	WALL = 12,
	KEY = 13,
	MAGE = 14
};

class Controller
{
public:
	Controller();
	~Controller();

	void run();
	void takeAction(const ItemInfo* item);
	void setSelectedItem(const ItemInfo* item);
	void addTeleport(const int& col, const int& row);
	void addCharacters(const std::string& character);
	void removeTeleport(const int& col, const int& row);
	void removeCharacter(const std::string& character);
	Board loadBoard();

	bool appearence(ItemInfo* itemInfo);

	ItemInfo* getItemInfo();
	int getMode();
	sf::Texture* getTexture(std::string textureName);

	char convertItemToChar(std::string item);

private:
	void loadBoardFile();
	void save();
	
	std::vector<sf::Vector2i> m_teleports;
	std::vector<std::string> m_characters;
	
	Menu m_menu;
	Board m_board;
	ItemInfo* m_itemInfo;
	std::vector<sf::Texture*> m_textures;

	int m_mode;
	bool m_boarded;
};

