#include <SFML/Graphics.hpp>
#include <iostream>

#include "Controller.h"

Controller::Controller():
	m_menu(13),
	m_board(5,5)
{
	
}


void Controller::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Level Editor"/*, sf::Style::Fullscreen*/);

	//m_menu = Menu(8);
	//m_board = Board(3, 3);
	
	m_board.setPosition({ 20,70});

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

void Controller::deleteItem(ItemInfo item)
{
	item.m_info = "Empty";

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

void Controller::setSelectedItem(ItemInfo item)
{

}

sf::Texture* Controller::getTexture(std::string name)
{
	return nullptr;
}

void Controller::saveBoard()
{

}

void Controller::addItem(const ItemInfo& item)
{
	m_itemInfo.m_info = item.m_info;

	m_itemInfo.m_texture = item.m_texture;
}