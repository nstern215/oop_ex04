#include "Components.h"


CompNode::CompNode(const Location& location, char c)
	:m_location(location), m_rep(c)	{}


//---------------------------------------------//

Componants::Components()
{
	m_compList = {K,M,W,T,=,#,*,!,F,X,@};
}

//---------------------------------------------//

Location Componants::getLocation()
{
	return m_component.m_location;
}

//---------------------------------------------//

char Componants::getRepresent()
{
	return 0;
}

//---------------------------------------------//



//---------------------------------------------//




//---------------------------------------------//





//---------------------------------------------//

