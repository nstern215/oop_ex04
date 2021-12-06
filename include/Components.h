#pragma once

#include <vector>

#include "Location.h"

struct CompNode {

	CompNode(const Location& location, char c);
	Location m_location;
	char m_rep;
};

class Componants {

public:

	Components();

	Location getLocation();

	char getRepresent();
		
protected:

	CompNode m_component;

private:

	std::vector<char> m_compList;

};