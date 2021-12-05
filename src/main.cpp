#include <cstdlib>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Board.h"

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Editor");

    Board board1(1, 10);
    Board board2(10, 10, 0, 150);
    

	while (window.isOpen())
	{
        window.clear();

        board1.draw(window);
        board2.draw(window);
        window.display();
		
        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:
                if (board1.getGlobalBound().contains(window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y})))
                {
                    board1.mouseButtonReleased(event, window);
                }
                else if (board2.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
                {
                    board2.mouseButtonReleased(event, window);
                }
                break;
            //case sf::Event::MouseMoved:
            //    std::cout << "mouse move" << std::endl;
            //    if (board1.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y })))
            //    /*if (board1.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))*/
            //    {
            //        board1.mouseMoved(event, window);
            //    }
            //    else if (board2.getGlobalBound().contains(window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y })))
            //    {
            //        board2.mouseMoved(event, window);
            //    }
            //    break;
            }
        }
	}
	
    return EXIT_SUCCESS;
}