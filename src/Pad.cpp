#include "Pad.h"

Pad::Pad(int id, Colors color, sf::Vector2f pos, bool is_free)
        : id(id), m_color(color), m_shape(sf::CircleShape(PAD_WIDTH * (sqrt(3.f) / 2), 6)), m_isFree(is_free) {
    m_shape.setFillColor(colors_arr[color]);
    m_shape.setPosition(pos);
    m_shape.setOutlineColor(sf::Color::White);
    m_shape.setOutlineThickness(.5);
}

void Pad::uniteToGroup(const Colors color) {
    m_isFree = false;
    m_shape.setFillColor(colors_arr[color]);
    m_color = color;

    // TODO unite all relevants
}

void Pad::draw(sf::RenderWindow &window) { window.draw(m_shape); }

Colors Pad::getColor() {
    return m_color; }

void Pad::setArray() {
    m_neighbors.fill(nullptr);
}
