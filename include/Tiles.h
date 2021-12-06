#pragma once

#include <vector>

class Characters;

struct CompNode;

class Tiles : public Componants {

public:

	Tiles();

	void addTile(const CompNode&);

	void getTiles(const int&, const int&, const char&, const int& telepNum);

	void clearTile(const int&);

	int getCellNum(const char&, const Location& location) const;

	Location teleportDes(const int&, const int&) const;

	Board TilesToBoard(Board& board);

private:

	std::vector<Node2> m_tilesList;



};