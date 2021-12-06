#include <Characters.h>

Characters::Characters()
{
}

//---------------------------------------------//

void Characters::addCharacter(const CompNode& character)
{
	m_charactersList.push_back(character);
}

//---------------------------------------------//

void Characters::switchCharacter()
{
	if (m_chrNum != (m_characters.size() - 1))
		m_chrNum++;
	else
		m_chrNum = 0;
}

//---------------------------------------------//

char Characters::getPlayerName()
{
	return m_characters[m_chrNum].m_c;
}


//---------------------------------------------//

bool Characters::kingWon()
{
	return m_throne;
}

//---------------------------------------------//


//---------------------------------------------//


//---------------------------------------------//




