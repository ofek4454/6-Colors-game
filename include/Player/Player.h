#pragma once
#include "set"
#include "Pad.h"

class Player{
public:
    Player(std::shared_ptr<Pad> initial_pad);
    virtual Colors play(Colors color) = 0;
protected:
    std::set<std::shared_ptr<Pad>> m_pads;
    void drawNeighbors(Colors color);
private:
    Colors m_color;
};
