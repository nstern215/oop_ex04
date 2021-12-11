#include <SFML/Graphics.hpp>
#include <fstream>
#include <filesystem>
#include "Controller.h"

#include <iostream>

#define BOARD_FILE_NAME "Board.txt"

Controller::Controller() :
	m_menu(8)
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
}


void Controller::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Level Editor"/*, sf::Style::Fullscreen*/);

	//m_board.resetAndResize(12, 12);

	//m_menu = Menu(8);
	//m_board = Board(3, 3);

	m_board.setPosition({ 20,70 });

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
						m_board.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
					}
					else if (m_menu.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_menu.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
					}
				}
			}
		}
	}
}

sf::Texture* Controller::getTexture(TextureIndex textureName)
{
	return m_textures[textureName];
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

		m_teleports.emplace_back(sourceRow, sourceCol, pairRow, pairCol);
	}

	file.close();
	
	m_board.load(board);
}
