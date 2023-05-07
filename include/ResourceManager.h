#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager{
public:
    static ResourceManager &instance();

    // functions
    sf::Font &getFont();
private:
    ResourceManager();
    sf::Font m_font;
};