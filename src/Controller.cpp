#include <SFML/Graphics.hpp>

#include "Controller.h"

Controller::Controller():
	m_board(3,3)
{
	
}


void Controller::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Level Editor"/*, sf::Style::Fullscreen*/);

	//m_menu = Menu(8);
	//m_board = Board(3, 3);

	while (window.isOpen())
	{
		window.clear();
		m_board.draw(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
}
