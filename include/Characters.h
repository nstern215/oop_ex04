#pragma once

#include "Board.h"

class Characters : public Board {

public:
	
	char getPlayerName();

	Location characterLocation();


private:

	int m_characterNum;

};