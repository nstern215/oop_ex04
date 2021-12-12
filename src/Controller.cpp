#include <SFML/Graphics.hpp>
#include <fstream>
#include <filesystem>
#include "Controller.h"

#include <iostream>

#define BOARD_FILE_NAME "Board.txt"

Controller::Controller() :
	m_itemInfo(nullptr)
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
											"save.png" };
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
		m_board.resetAndResize(row, col);
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
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Level Editor");

	m_board.setPosition({ 70,70 });

	while (window.isOpen())
	{
		window.clear();
		m_board.draw(window);
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
	else if(item->m_itemData == "SAVE")
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
		if ((m_teleports[i].x == col)||(m_teleports[i].y == row))
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

sf::Texture* Controller::getTexture(const int& texturId)
{
	return m_textures[texturId];
}