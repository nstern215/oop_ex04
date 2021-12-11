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
						m_board.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), (m_itemInfo.m_texture), (m_itemInfo.m_itemData));
					}
					else if (m_menu.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					{
						m_menu.onMouseClick(event, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), (m_itemInfo.m_texture), (m_itemInfo.m_itemData));
					}
				}
			}
		}
	}
}

void Controller::takeAction(const ItemInfo& item)
{
	if (item.m_itemData == "DELETE")
	{
		deleteItem();
	}
	else if (item.m_itemData == "ADD")
	{
		addItem(item);
	}
	else if(item.m_itemData == "SAVE")
	{
		saveBoard();
	}
	else
{
		clearBoard();
	}
}

void Controller::deleteItem(ItemInfo item)
{
	item.m_itemData = ' ';

	item.m_texture = nullptr;
}
	
void Controller::clearBoard()
{
	for ()
	{
		for () 
	{
			deleteItem();
		}
	}

}



	}

void Controller::addItem(const ItemInfo& item)
	{
	m_itemInfo.m_itemData = item.m_itemData;

	m_itemInfo.m_texture = item.m_texture;
	}

