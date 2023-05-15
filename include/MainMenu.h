#pragma once

#include "Consts.h"
#include "SFML/Graphics.hpp"
#include "Player.h"

class MainMenu {
public:
    MainMenu();
    void getEvents();
    void printMenu();
    void handleHover();
    void handleClick(sf::Event::MouseButtonEvent &click);
    void printHelp();

private:
    sf::RenderWindow m_window;
    sf::RectangleShape m_background;
    sf::Text m_texts[NUM_OF_BUTTONS];
    sf::Texture m_textures[NUM_OF_BUTTONS];
    std::string m_textNames[NUM_OF_BUTTONS] = {"1P Vs Random","1P Vs Smart","1P Vs Smarter","2P","Help","Quit"};
    sf::Font m_font;

    std::unique_ptr<Player> players[2];

};
