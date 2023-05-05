#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"

class Controller {
public:
    Controller();
    void run();
private:
    void printWindowObjects();
    sf::RenderWindow m_window;
    Board m_board;
};
