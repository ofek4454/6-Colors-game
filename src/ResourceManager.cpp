//
// Created by Ofek Gorgi on 07/05/2023.

//
#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    m_font.loadFromFile("../../../PressStart2P.ttf");
}

ResourceManager &ResourceManager::instance() {
    static ResourceManager inst;
    return inst;
}

sf::Font &ResourceManager::getFont() {
    return m_font;
}
