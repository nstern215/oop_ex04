#include <SFML/Graphics.hpp>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "Controller.h"

#define BOARD_FILE_NAME "Board.txt"
#define FONT_PATH "C:/Windows/Fonts/Arial.ttf"

Controller::Controller()
{
	m_itemInfo = new ItemInfo();
	m_itemInfo->m_texture = nullptr;
	m_itemInfo->m_itemData = " ";

	loadTextures();

	if (!std::filesystem::exists(BOARD_FILE_NAME))
		setNewBoard();
	else
		loadBoardFile();

	m_menu.init(*this);
}

Controller::~Controller()
{
	delete m_itemInfo;
}

void Controller::run()
{
	 auto window = sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Board Editor");

	m_board.setPosition({ 0,150 });

	auto font = sf::Font();
	font.loadFromFile(FONT_PATH);
	sf::Text mode(std::to_string(0), font);
	mode.setFillColor(sf::Color::White);
	mode.setPosition(20, 85);

	while (window.isOpen())
	{
		mode.setString(getInfoString());

		window.clear();
		m_board.draw(window);
		window.draw(mode);
		m_menu.draw(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (m_board.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_board.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), *this);
					}
					else if (m_menu.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_menu.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), *this);
					}
				}
			}
		}
	}
}

void Controller::takeAction(const std::string& command)
{
	if (command == "DELETE")
	{
		m_mode = DELETE;
		m_itemInfo->m_itemData = " ";
		m_itemInfo->m_texture = nullptr;
	}
	else if (command == "SAVE")
		save();
	else 
		setNewBoard();
}

void Controller::setSelectedItem(const ItemInfo* item)
{
	if (m_mode == DELETE)
		m_mode = 0;
	else
		m_mode = 1;

	m_itemInfo->m_itemData = item->m_itemData;
	m_itemInfo->m_texture = item->m_texture;
}

void Controller::addTeleport(const int& col, const int& row)
{
	sf::Vector2i location;

	location.x = col;
	location.y = row;

	m_teleports.push_back(location);
}

void Controller::addCharacters(const std::string& character)
{
	m_characters.push_back(character);
}

void Controller::removeTeleport(const int& col, const int& row)
{
	for (int i = 0; i < m_teleports.size(); i++)
		if ((m_teleports[i].x == col) || (m_teleports[i].y == row))
			m_teleports.erase(m_teleports.begin() + i);
}

void Controller::removeCharacter(const std::string& character)
{
	for (int i = 0; i < m_characters.size(); i++)
		if (m_characters[i] == character)
			m_characters.erase(m_characters.begin() + i);
}

bool Controller::appearence(const std::string& character)
{
	for (int i = 0; i < m_characters.size(); i++)
		if (m_characters[i] == character)
			return true;
	return false;
}

ItemInfo* Controller::getItemInfo()
{
	return m_itemInfo;
}

int Controller::getMode()
{
	return m_mode;
}

void Controller::loadBoardFile()
{
	m_teleports.clear();
	
	std::ifstream file;
	file.open(BOARD_FILE_NAME);

	std::vector<std::string> board;

	while (!file.eof())
	{
		std::string line;
		file >> line;

		if (line.empty())
			continue;

		if (line[0] == '-')
			break;

		board.emplace_back(line);
	}
	
	while (!file.eof())
	{
		int sourceRow;
		int sourceCol;
		int pairRow;
		int pairCol;

		file >> sourceRow >> sourceCol >> pairRow >> pairCol;

		m_teleports.emplace_back(sourceRow, sourceCol);
		m_teleports.emplace_back(pairRow, pairCol);
	}

	file.close();

	m_board.load(board, *this);
}

sf::Texture* Controller::getTexture(std::string textureName)
{
	

	if (textureName == "KING")
		return m_textures[0];
	if (textureName == "FIRE")
		return m_textures[1];
	if (textureName == "GATE")
		return m_textures[2];
	if (textureName == "ORK")
		return m_textures[3];
	if (textureName == "THIEF")
		return m_textures[4];
	if (textureName == "WARRIOR")
		return m_textures[5];
	if (textureName == "TELEPORT")
		return m_textures[6];
	if (textureName == "THRONE")
		return m_textures[7];
	if (textureName == "DELETE")
		return m_textures[8];
	if (textureName == "CLEAR")
		return m_textures[9];
	if (textureName == "SAVE")
		return m_textures[10];
	if (textureName == "ADD")
		return m_textures[11];
	if (textureName == "WALL")
		return m_textures[12];
	if (textureName == "MAGE")
		return m_textures[13];

	return nullptr;
}

void Controller::save()
{
	std::vector<std::string> lines = m_board.save(*this);
	if (m_teleports.size() % 2 != 0)
	{
		const auto location = m_teleports[m_teleports.size() - 1];
		lines[location.x - 1][location.y - 1] = ' ';
	}
	std::ofstream file("Board.txt", 'w');
	if (file.is_open())
	{
		for (auto& line : lines)
			file << line << std::endl;
		file << '-' << std::endl;
		int teleportsAmount = m_teleports.size();
		if (teleportsAmount % 2 != 0)
			teleportsAmount--;
		for (int i = 0; i < teleportsAmount - 1; i += 2)
		{
			file << std::to_string(m_teleports[i].x)
				<< " "
				<< std::to_string(m_teleports[i].y)
				<< " "
				<< std::to_string(m_teleports[i + 1].x)
				<< " "
				<< std::to_string(m_teleports[i + 1].y)
				<< std::endl;
		}
		file.close();
	}
}

char Controller::convertItemToChar(std::string item) const
{
	if (item == "KING")
		return 'K';
	if (item == "FIRE")
		return '*';
	if (item == "GATE")
		return '#';
	if (item == "ORK")
		return 'O';
	if (item == "THIEF")
		return 'T';
	if (item == "WARRIOR")
		return 'W';
	if (item == "TELEPORT")
		return 'X';
	if (item == "THRONE")
		return '@';
	if (item == "WALL")
		return '=';
	if (item == "MAGE")
		return 'M';
	return '_';
}

std::string Controller::convertChatToItem(char c) const
{
	switch (c) {
	case 'K':
		return "KING";
	case '*':
		return "FIRE";
	case '#':
		return "GATE";
	case 'O':
		return "ORK";
	case 'T':
		return "THIEF";
	case 'W':
		return "WARRIOR";
	case 'X':
		return "TELEPORT";
	case '@':
		return "THRONE";
	case '=':
		return "WALL";
	case 'M':
		return "MAGE";
	default:
		return " ";
	}
}

std::string Controller::getInfoString() const
{
	std::string dataString;
	dataString += "Edit Mode: ";

	/*if (m_mode == ) // create new board
		dataString = "Enter new board dimensions in terminal window";
	else*/ if (m_mode == 0)
		dataString += "Delete";
	else
	{
		dataString += "Add ";
		dataString += m_itemInfo->m_itemData;
	}
	
	return dataString;
}

void Controller::setNewBoard()
{
	int row;
	int col;

	std::cout << "Please enter board size: row and cols" << std::endl;
	std::cin >> row >> col;

	const auto displayMode = sf::VideoMode::getDesktopMode();
	const int windowWidth = displayMode.width;
	const int windowHeight = displayMode.height;
	const int maxRow = (windowHeight - 100) / DEFAULT_WIDTH;
	const int maxCol = (windowWidth - 40) / DEFAULT_HEIGHT;
	
	m_board.resetAndResize(std::min(row, maxRow), std::min(col, maxCol));

}

void Controller::loadTextures()
{
	std::vector<std::string> textureName = { "crown.png",
											"fire.png",
											"gate.png",
											"ork.png",
											"thief.png",
											"warrior.png",
											"teleport.png",
											"throne.png",
											"delete.png",
											"open.png",
											"save.png",
											"add.png",
											"wall.png",
											"mage.png" };
	int counter = 0;
	for (auto& t : textureName)
	{
		m_textures.push_back(new sf::Texture());
		m_textures[counter++]->loadFromFile(t);
	}
}
