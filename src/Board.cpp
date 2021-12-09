#include "Board.h"

#include "BoardItem.h"

Board::Board(const unsigned row, const unsigned col) :
	Matrix(row, col)
{
	for (int i = 0; i < m_row; i++)
	{
		m_items.emplace_back();
		for (int j = 0; j < m_col; j++)
			m_items[i].push_back(new BoardItem(i, j));
	}
}

Board::~Board()
{
	for (auto& v : m_items)
		for (auto* item : v)
			delete item;
}

//void Board::onMouseClick(sf::Event& event, sf::Vector2f location, const char& display)
//{
//
//}


void Board::draw(sf::RenderWindow& window)
{
	for (auto& v : m_items)
		for (auto*& item : v)
			item->draw(window);
}