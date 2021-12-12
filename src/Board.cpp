#include "Board.h"

#include "BoardItem.h"
#include "Controller.h"

Board::Board( unsigned int row, unsigned int col) :
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
			m_items[i].push_back(new BoardItem(nullptr, i, j));
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
	sf::Vector2f position = m_items[0][0]->getPosition();
	
	int row = content.size();
	int col = content[0].size();

	resetAndResize(row, col);

	setPosition(position);
	
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
		{
			//todo: load
		}
}

std::vector<std::string> Board::save(Controller& controller)
{
	std::vector<std::string> lines;

	for (auto& boardLine : m_items)
	{
		std::string line;
		
		for(auto*& item : boardLine)
			line += controller.convertItemToChar(item->getInfo());

		lines.push_back(line);
	}
	
	return lines;
}
