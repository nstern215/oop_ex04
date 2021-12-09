#pragma once

#include "MatrixItem.h"

#include <vector>

class MenuItem : public MatrixItem {

public:

	MenuItem(int col, char display = ' ', float positionOffsetX = 0, float positionOffsetY = 0);

	void setDisplay();

	char onMouseClick(sf::Event& event, sf::Vector2f location, char command);


private:

	std::vector<char> m_listDisplay = { 'K','M','W','T','@','!','F','#','=','*','D','C','S' };
	
};