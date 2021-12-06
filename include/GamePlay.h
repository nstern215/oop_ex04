#pragma once

class Characters;
class Tiles;
class Board;
struct Location;

enum Keys
{
	KB_Escape = 27,
	SpecialKey = 112,
};

enum SpecialKeys
{
	KB_Up = 72,
	KB_Down = 80,
	KB_Left = 75,
	KB_Right = 77,
};

class GamePlay {

public:

	void start();

	void move( Characters& );

	void moveReaction( Characters&, Tiles& );

	void endGame();

private:

	// this function will do all the actions in order//

	void startPlay(Characters& chr, const Board& b);

	// this function will clear the board for new print//

	void clearBoard();
};