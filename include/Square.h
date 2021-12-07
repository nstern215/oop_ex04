#pragma once

#include <SFML/Graphics.hpp>

#define DEFAULT_WIDTH 50.0
#define DEFAULT_HEIGHT 50.0

class Square
{
public:
    Square(const float width = DEFAULT_WIDTH, const float height = DEFAULT_HEIGHT,\
        sf::Vector2f origin = {0,0}, sf::Vector2f position = {0,0}, sf::Texture* texture = nullptr,
        sf::Color bgColor = sf::Color::White);
    
    virtual void draw(sf::RenderWindow& window);

    void setWidth(float width);
    void setHeight(float height);

    float getWidth() const;
    float getHeight() const;

	//todo: test reference
    void setOrigin(const sf::Vector2f& origin);
    void setPosition(const sf::Vector2f& position);
    void setTexture(sf::Texture* texture);
    void removeTexture();
	
    sf::FloatRect getGlobalBound();

private:
    float m_width;
    float m_height;
    sf::Color m_bgColor;
    sf::Vector2f m_origin;
    sf::Vector2f m_position;
    sf::Texture* m_texture;
};