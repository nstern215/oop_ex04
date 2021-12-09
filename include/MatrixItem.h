#pragma once

#include <SFML/Graphics.hpp>

#include "Square.h"
#include "MatrixItem.h"

//struct Item {
//
//    Item();
//
//    Square m_square;
//
//    char m_display;
//    int m_row;
//    int m_col;
//};


class MatrixItem {

public:
    MatrixItem(int row = 0, int col = 0, char display=' ', float positionOffsetX = 0, float positionOffsetY = 0);
    virtual ~MatrixItem();
	
    virtual void draw(sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float positionOffsetX, float positionOffsetY);
    void setDisplay(char display);

    virtual char getDsiplay() const;

    sf::Vector2f getPosition() const;
	
    sf::FloatRect getGlobalBound();
	
    virtual char onMouseClick(sf::Event& event, sf::Vector2f location, char command);

protected:
    
    /*Item m_item;*/
    Square m_square;

    char m_display;
    int m_row;
    int m_col;
};