#pragma once

#include <SFML/Graphics.hpp>

#define DEFAULT_WIDTH 85.0
#define DEFAULT_HEIGHT 85.0

class Square
{
public:
    Square(const float width = DEFAULT_WIDTH, const float height = DEFAULT_HEIGHT,
        sf::Vector2f position = {0,0}, sf::Texture* texture = nullptr,
        sf::Color bgColor = sf::Color::White);

    Square(const Square& other);

    Square& operator=(const Square& other);
	
    virtual void draw(sf::RenderWindow& window);

    void setWidth(float width);
    void setHeight(float height);

    float getWidth() const;
    float getHeight() const;

    void setPosition(const sf::Vector2f position);
    sf::Vector2f getPosition() const;
	
    void setTexture(sf::Texture* texture);
    sf::Texture* getTexture() const;
    void removeTexture();

    void setBgColor(sf::Color color);
    sf::Color getBgColor() const;
	
    sf::FloatRect getGlobalBound() const;

private:
    float m_width;
    float m_height;
    sf::Color m_bgColor;
    sf::Vector2f m_position;
    sf::Texture* m_texture;
};