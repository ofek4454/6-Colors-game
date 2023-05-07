#pragma once

#include "Mosaic.h"
#include "Pad.h"

class Board {
public:
    ~Board() = default;
    void create();
    void printBoardObject(sf::RenderWindow &window);
    void attachNeighbors();
    std::shared_ptr<Pad> getBottomLeftCorner();
    std::shared_ptr<Pad> getTopRightCorner();
private:
    void initOverlay(float starting_x, float starting_y, float width, float height);
    Mosaic<Mosaic<std::shared_ptr<Pad>>> m_pads;
    sf::RectangleShape m_overlay[5];
};


