
#include "ColorBtn.h"


ColorBtn::ColorBtn() {}

ColorBtn::ColorBtn(Colors color, sf::Vector2f pos, bool disabled)
    : m_color(color), m_btn(sf::RectangleShape(sf::Vector2f(BUTTON_SIZE, BUTTON_SIZE))), m_disabled(disabled){
    m_btn.setPosition(pos);
    sf::Color c(colors_arr[color].r,colors_arr[color].g,colors_arr[color].b);
    m_btn.setFillColor(c);
    m_btn.setOutlineColor(sf::Color::White);
    m_btn.setOutlineThickness(2);

    m_disabledText.setFont(ResourceManager::instance().getFont());
    m_disabledText.setString("X");
    m_disabledText.setOrigin(m_disabledText.getGlobalBounds().width/2,m_disabledText.getGlobalBounds().height/2);
    m_disabledText.setFillColor(sf::Color::White);
    m_disabledText.setPosition(m_btn.getPosition().x +m_btn.getGlobalBounds().width/2, m_btn.getPosition().y+m_btn.getGlobalBounds().height/2);
    m_disabledText.setOutlineColor(sf::Color::Black);
    m_disabledText.setOutlineThickness(1);
}

bool ColorBtn::isPressed(sf::Event::MouseButtonEvent event) {
    return m_btn.getGlobalBounds().contains(event.x, event.y);
}

void ColorBtn::draw(sf::RenderWindow &window) {
    window.draw(m_btn);
    if(m_disabled)
        window.draw(m_disabledText);
}

void ColorBtn::setDisabled(bool disable) {
    m_disabled = disable;
}
