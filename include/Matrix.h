#pragma once

#include <vector>
#include "MatrixItem.h"


class Matrix {
public:
	Matrix(const unsigned int row = 0, const unsigned int col = 0);

	virtual ~Matrix();

	virtual void draw(sf::RenderWindow& window);
	virtual void setPosition(const sf::Vector2f& position);

	sf::FloatRect getGlobalBound();

	virtual void onMouseClick(sf::Event& event, sf::Vector2f location, sf::Texture* itemTexture, std::string itemData);

protected:
	std::vector<std::vector<MatrixItem*>> m_items;

	unsigned int m_row;
	unsigned int m_col;

	Controller m_controller;
};