#pragma once

#include <SFML/Graphics.hpp>

class SharedData
{
public:
	SharedData();
	
	sf::Texture& getCrown();
private:
	sf::Texture m_crown;
};
