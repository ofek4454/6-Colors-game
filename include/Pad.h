#pragma once
#include "Consts.h"

class Pad {
public:
    Pad(const sf::Color color, sf::Vector2f pos,bool is_free = true);
    void draw(sf::RenderWindow &window);
    void pick(const sf::Color color);
private:
    bool m_isFree;
    sf::Vector2f m_position;
    sf::CircleShape m_shape;
};