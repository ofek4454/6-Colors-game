#pragma once

#include "Mosaic.h"
#include "Pad.h"

class Board {
public:
    Board() : m_pads(Mosaic<Pad,NUM_OF_ROWS,NUM_OF_COLS>()){create();}
    void create();
    void printBoardObject(sf::RenderWindow &window);
private:
    Mosaic<Pad,NUM_OF_ROWS,NUM_OF_COLS> m_pads;
};


