#include "MatrixItem.h"

MatrixItem::MatrixItem(ItemInfo* itemInfo, int row, int col, float positionOffsetX, float positionOffsetY) :
	m_row(row),
	m_col(col),
	m_itemInfo(itemInfo)
{
	setPosition(positionOffsetX, positionOffsetY);

	if (!m_itemInfo)
	{
		m_itemInfo = new ItemInfo();
		m_itemInfo->m_texture = nullptr;
		m_itemInfo->m_itemData = " ";
	}
}

MatrixItem::~MatrixItem()
{
	delete m_itemInfo;
};

void MatrixItem::draw(sf::RenderWindow& window)
{
	m_square.draw(window);
}

void MatrixItem::setPosition(const sf::Vector2f& position)
{
	setPosition(position.x, position.y);
}

void MatrixItem::setPosition(float positionOffsetX, float positionOffsetY)
{
	m_square.setPosition({ m_col * m_square.getWidth() + positionOffsetX,
		m_row * m_square.getHeight() + positionOffsetY });
}


sf::Vector2f MatrixItem::getPosition() const
{
	return m_square.getPosition();
}


sf::FloatRect MatrixItem::getGlobalBound()
{
	return m_square.getGlobalBound();
}

void MatrixItem::onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller)
{
}

std::string MatrixItem::getInfo() const
{
	return m_itemInfo->m_itemData;
}

void MatrixItem::setInfo(std::string info)
{
	m_itemInfo->m_itemData = info;
}

void MatrixItem::setTexture(sf::Texture* texture)
{
	m_square.setTexture(texture);
}
