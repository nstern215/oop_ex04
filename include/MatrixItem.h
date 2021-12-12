#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"
#include "Controller.h"

struct ItemInfo
{
    ItemInfo():m_texture(nullptr), m_itemData(" "){}

    int m_type;
    sf::Texture* m_texture;
    std::string m_itemData;
};

class MatrixItem {

public:
    MatrixItem(int row = 0, int col = 0, float positionOffsetX = 0, float positionOffsetY = 0);
    virtual ~MatrixItem();
	
    virtual void draw(sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float positionOffsetX, float positionOffsetY);
    void setInfo(std::string info);
    void setTexture(sf::Texture* texture);

    virtual std::string getInfo() const;

    sf::Vector2f getPosition() const;
	
    sf::FloatRect getGlobalBound();

   /* std::string print();*/
	
    virtual void onMouseClick(sf::Event& event, sf::Vector2f location, Controller& controller, const int& mode, ItemInfo itemInfo);

protected:

    Square m_square;
    ItemInfo m_itemInfo;

    int m_row;
    int m_col;
};