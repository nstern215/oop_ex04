#include "Matrix.h"

Matrix::Matrix(const unsigned int row, const unsigned int col):
    m_row(row),
    m_col(col)
{}

Matrix::~Matrix()
{
	freeMemory();
}

void Matrix::init(Controller& controller)
{}

void Matrix::draw(sf::RenderWindow& window)
{
	for (auto& v : m_items)
		for (auto*& item : v)
			item->draw(window);
}

void Matrix::setPosition(const sf::Vector2f& position)
{
	for (auto& v : m_items)
		for (auto* item : v)
			item->setPosition(position);
}

sf::FloatRect Matrix::getGlobalBound()
{
	auto topLeft = m_items[0][0]->getPosition();
	auto bottomRight= m_items[m_row - 1][m_col - 1]->getGlobalBound();

	auto bound = sf::FloatRect(topLeft, { bottomRight.left + bottomRight.width, bottomRight.top + bottomRight.height });
	
	return bound;
}

void Matrix::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
	for (auto& v : m_items)
		for (auto*& item : v)
			if (item->getGlobalBound().contains(location))
			{
				item->onMouseClick(event, location, controller);
				return;
			}
}

void Matrix::freeMemory()
{
	for (auto& v:m_items)
		for(auto*& item:v)
			delete item;
}

void Matrix::initMatrix()
{
	for (int i=0;i<m_row;i++)
	{
		m_items.emplace_back();
		for (int j = 0; j < m_col; j++)
			m_items[i].push_back(new MatrixItem(nullptr, i,j));
	}
}

void Matrix::resetAndResize(int row, int col)
{
	m_row = row;
	m_col = col;

	freeMemory();

	m_items.clear();

	initMatrix();
}

int Matrix::getCol() const
{
	return m_col;
}

int Matrix::getRow() const
{
	return m_row;
}

