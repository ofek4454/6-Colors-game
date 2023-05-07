#pragma once
#include "Consts.h"
#include "ResourceManager.h"

class ColorBtn{
public:
    ColorBtn();
    ColorBtn(Colors color, sf::Vector2f pos, bool disabled = false);

    void draw(sf::RenderWindow &window);
    bool isPressed(sf::Event::MouseButtonEvent event);
    Colors getColor(){return m_color;}

private:
    Colors m_color;
    sf::RectangleShape m_btn;
    sf::Text m_disabledText;
    bool m_disabled;
};
