#include "Matrix.h"

Matrix::Matrix(const unsigned int row, const unsigned int col):
    m_row(row),
    m_col(col)
{}

Matrix::~Matrix() = default;

void Matrix::draw(sf::RenderWindow& window)
{
	for (auto& v : m_items)
		for (auto* item : v)
			item->draw(window);
}

