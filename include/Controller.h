#pragma once
#include "SFML/Graphics.hpp"
#include "Consts.h"

class Controller {
public:
    Controller();
private:
    void run();
    void printWindowObjects();
    sf::RenderWindow m_window;

};
