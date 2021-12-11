#include <SFML/Graphics.hpp>

#include "Controller.h"

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
}


void Controller::run()
{
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Level Editor"/*, sf::Style::Fullscreen*/);

	m_board.resetAndResize(12, 12);

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
