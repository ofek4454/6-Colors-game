#include "Pad.h"

Pad::Pad(int id, const int vertices, Colors color, sf::Vector2f pos, bool is_free)
        : m_id(id), m_color(color), m_shape(sf::CircleShape(PAD_WIDTH * (sqrt(3.f) / 2), vertices)), m_isFree(is_free) {
    m_shape.setFillColor(colors_arr[color]);
    m_shape.setPosition(pos);
    m_shape.setOutlineColor(sf::Color::White);
    m_shape.setOutlineThickness(.5);
}

void Pad::draw(sf::RenderWindow &window) { window.draw(m_shape); }

Colors Pad::getColor() {
    return m_color;
}

void Pad::setColor(Colors color) {
    m_color = color;
    m_shape.setFillColor(colors_arr[color]);
}

void Pad::setOutline(bool outline_on) {
    if (outline_on) {
        m_shape.setOutlineThickness(2);
    } else {
        m_shape.setOutlineThickness(.5);
    }
}