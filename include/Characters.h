#pragma once

#include <vector>

//class Board;
//class Tiles;

struct CompNode;

class Characters : public Componants {

public:

	Characters();

	void addCharacter(const CompNode&);

	void switchCharacter();

	void reAct(const char& c, Tiles& tile);

	bool kingWon();

	char getPlayerName();

	Board CharactersToBoard(Board& board);

private:

	Location teleport(const Tiles& tile);

	std::vector<CompNode> m_charactersList;

	int m_chrNum = 0;

	bool m_key = false;
	bool m_throne = false;
};
