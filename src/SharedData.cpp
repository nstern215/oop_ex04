#include "SharedData.h"

#include <iostream>

#define CROWN "crown.png"

SharedData::SharedData()
{
	bool result = m_crown.loadFromFile(CROWN);

	std::cout << "crown loadded: " << result << std::endl;
}

sf::Texture& SharedData::getCrown()
{
	return m_crown;
}

