#pragma once
#include "Consts.h"

class Pad {
public:
    Pad(const sf::Color color = sf::Color::Green, sf::Vector2f pos = sf::Vector2f(0,0),bool is_free = true);
    void draw(sf::RenderWindow &window);
    void pick(const sf::Color color);
    bool getfree() const { return m_isFree;}
private:
    bool m_isFree;
    sf::Vector2f m_position;
    sf::CircleShape m_shape;
};
std::ostream& operator<<(std::ostream& os, const Pad& pad);
