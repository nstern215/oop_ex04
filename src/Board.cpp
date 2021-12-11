#include "Board.h"

#include "BoardItem.h"

Board::Board(const unsigned row, const unsigned col) :
	Matrix(row, col)
{
	initMatrix();
}

Board::~Board()
{
	freeMemory();
}

void Board::draw(sf::RenderWindow& window)
{
	for (auto& v : m_items)
		for (auto*& item : v)
			item->draw(window);
}

void Board::initMatrix()
{
	for (int i = 0; i < m_row; i++)
	{
		m_items.emplace_back();
		for (int j = 0; j < m_col; j++)
			m_items[i].push_back(new BoardItem(i, j));
	}
}

void Board::freeMemory()
{
	for (auto& v : m_items)
		for (auto*& item : v)
		{
			delete item;
			item = nullptr;
		}
}

void Board::load(std::vector<std::string> content)
{
	int row = content.size();
	int col = content[0].size();

	resetAndResize(row, col);

	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
		{
			//todo: load
		}
}

