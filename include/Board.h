#pragma once

#include "Mosaic.h"
#include "Pad.h"

class Board {
public:
    Board(){create();}
    void create();
    void printBoardObject(sf::RenderWindow &window);
private:
    Mosaic<Mosaic<Pad>> m_pads;
    sf::RectangleShape m_overlay[5];
};


