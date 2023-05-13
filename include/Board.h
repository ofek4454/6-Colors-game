#pragma once

#include "SFML/Graphics.hpp"
#include "vector"
#include "memory"
#include "GraphNode.h"
#include "Consts.h"

class Board {
public:
    virtual void create() = 0;
    virtual ~Board() = default;
    virtual void attachNeighbors() = 0;
    void blur(sf::RenderWindow &window);
    void initOverlay(float starting_x, float starting_y, float width, float height);
protected:
    sf::RectangleShape m_overlay[5];
private:

};

