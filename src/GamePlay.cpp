#include <GamePlay.h>


void GamePlay::start()
{
}

//---------------------------------------------//

void GamePlay::move(Characters&)
{
}

//---------------------------------------------//

void GamePlay::moveReaction(Characters&, Tiles&)
{
}

//---------------------------------------------//

void GamePlay::endGame()
{
}

//---------------------------------------------//

void GamePlay::move(Characters& chr, Tiles& tile)
{
	bool validPlay = false;
	int row;
	int col;

	while (!validPlay)
	{
		auto c = _getch();

		switch (c)
		{
		case KB_Up:
			row = -1;
			col = 0;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case KB_Down:
			row = 1;
			col = 0;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case KB_Left:
			row = 0;
			col = -1;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case KB_Right:
			row = 0;
			col = 1;
			chr.move(b, row, col);
			validPlay = true;
			break;

		case 'p':
			chr.switchCharacter();
			validPlay = true;
			break;

		case KB_Escape:
			endGame();
			validPlay = true;

		}
	}
}

//---------------------------------------------//
//---------------------------------------------//
//---------------------------------------------//
//---------------------------------------------//

