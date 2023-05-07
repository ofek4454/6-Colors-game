
#include "ColorBtn.h"


ColorBtn::ColorBtn() {}

ColorBtn::ColorBtn(Colors color, sf::Vector2f pos, bool disabled)
    : m_color(color), m_btn(sf::RectangleShape(sf::Vector2f(BUTTON_SIZE, BUTTON_SIZE))){
    m_btn.setPosition(pos);
    m_btn.setFillColor(colors_arr[color]);
    m_btn.setOutlineColor(sf::Color::White);
    m_btn.setOutlineThickness(2);
}

bool ColorBtn::isPressed(sf::Event::MouseButtonEvent event) {
    return m_btn.getGlobalBounds().contains(event.x, event.y);
}

void ColorBtn::draw(sf::RenderWindow &window) {
    window.draw(m_btn);
}
