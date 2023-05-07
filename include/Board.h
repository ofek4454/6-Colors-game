#pragma once

#include "Mosaic.h"
#include "Pad.h"

class Board {
public:
    Board(){create();}
    void create();
    void printBoardObject(sf::RenderWindow &window);
    void attachNeighbors();
private:
    void initOverlay(float starting_x, float starting_y, float width, float height);
    Mosaic<Mosaic<Pad>> m_pads;
    sf::RectangleShape m_overlay[5];
};


