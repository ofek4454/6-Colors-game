#pragma once
#include "set"
#include "Pad.h"

class Player{
public:
    Player();
    void setPad(std::shared_ptr<Pad> new_pad);
    virtual Colors play(Colors color, Colors *lastChoosed) = 0;
    virtual ~Player() = default;
    int getNumOfPads();
protected:
    std::set<std::shared_ptr<Pad>> m_pads;
    void drawNeighbors(Colors color);
    Colors m_color;
private:
};
