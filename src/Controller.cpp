#include <SFML/Graphics.hpp>
#include <fstream>
#include <filesystem>
#include "Controller.h"

#include <iostream>

#define BOARD_FILE_NAME "Board.txt"

Controller::Controller()
{
	m_itemInfo = new ItemInfo();
	m_itemInfo->m_texture = nullptr;
	m_itemInfo->m_itemData = " ";
	
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
											"key.png",
											"mage.png"};
	int counter = 0;
	for (auto& t : textureName)
	{
		m_textures.push_back(new sf::Texture());
		m_textures[counter++]->loadFromFile(t);
	}

	if (!std::filesystem::exists(std::filesystem::current_path().string() + "\\Board.txt"))
	{
		int row, col;
		std::cout << "Please enter board size: row and cols" << std::endl;
		std::cin >> row >> col;
		m_board.resetAndResize(std::min(row, 10), std::min(col, 10));
	}
	else
	{
		//loadBoard
	}

	m_menu.init(*this);
}

Controller::~Controller()
{
	delete m_itemInfo;
}

void Controller::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(1200, 1000), "Level Editor");

	m_board.setPosition({0,150});

	auto font = sf::Font();
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	sf::Text mode(std::to_string(0), font);
	mode.setFillColor(sf::Color::White);
	mode.setPosition(20, 85);
	
	while (window.isOpen())
	{
		std::string dataString;
		dataString += "Mode: ";
		dataString += std::to_string(m_mode);
		dataString += " item: ";
		dataString += m_itemInfo->m_itemData;
		mode.setString(dataString);
		
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

void Controller::takeAction(const ItemInfo* item)
{
	if (item->m_itemData == "DELETE")
	{
		m_mode = DELETE;
		m_itemInfo->m_itemData = " ";
		m_itemInfo->m_texture = nullptr;
	}
	else if (item->m_itemData == "SAVE")
	{

	}
	else
	{
		//todo:check if need to reset!!!!!!!!

		const auto bound = m_board.getGlobalBound();
		const sf::Vector2f position(bound.left, bound.top);
		m_board.resetAndResize(m_board.getRow(), m_board.getCol());
		m_board.setPosition(position);
	}
}

void Controller::setSelectedItem(const ItemInfo* item)
{
	if (m_mode == DELETE)
	{
		m_mode = 0;
	}

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

void Controller::removeTeleport(const int& col, const int& row)
{
	for (int i = 0; i < m_teleports.size(); i++)
	{
		if ((m_teleports[i].x == col) || (m_teleports[i].y == row))
		{
			m_teleports.erase(m_teleports.begin() - i);
		}
	}
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
	std::ifstream file;
	file.open(std::filesystem::current_path().string() + "\\Board.txt");

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

	m_board.load(board);
}

sf::Texture* Controller::getTexture(std::string textureName)
{
	/*CROWN = 0,
		FIRE = 1,
		GATE = 2,
		ORK = 3,
		THIEF = 4,
		WARRIOR = 5,
		TELEPORT = 6,
		THRONE = 7,
		DELETE = 8,
		OPEN = 9,
		SAVE = 10*/

	int index = 0;

	if (textureName == "KING")
		index = 0;
	else if (textureName == "FIRE")
		index = 1;
	else if (textureName == "GATE")
		index = 2;
	else if (textureName == "ORK")
		index = 3;
	else if (textureName == "THIEF")
		index = 4;
	else if (textureName == "WARRIOR")
		index = 5;
	else if (textureName == "TELEPORT")
		index = 6;
	else if (textureName == "THRONE")
		index = 7;
	else if (textureName == "DELETE")
		index = 8;
	else if (textureName == "CLEAR")
		index = 9;
	else if (textureName == "SAVE")
		index = 10;
	else if (textureName == "ADD")
		index = 11;
	else if (textureName == "WALL")
		index = 12;
	else if (textureName == "KEY")
		index = 13;
	else if (textureName == "MAGE")
		index = 14;
	
	return m_textures[index];
}