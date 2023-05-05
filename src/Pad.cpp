#include "Pad.h"
Pad::Pad(const sf::Color color, sf::Vector2f pos,bool is_free) : m_shape(sf::CircleShape(PAD_WIDTH,6)),m_isFree(is_free){
    m_shape.setRadius(PAD_WIDTH);
    m_shape.setFillColor(color);
    m_shape.setPosition(pos);
}

void Pad::pick(const sf::Color color) {m_isFree = false; m_shape.setFillColor(color);}

void Pad::draw(sf::RenderWindow &window) {window.draw(m_shape);}


std::ostream& operator<<(std::ostream& os, const Pad& pad) {
    os << "(" << pad.getfree();
    return os;
}