#pragma once
#include "vector"
#include "Pad.h"

class Player{
public:
    Player(std::shared_ptr<Pad> initial_pad);
    void play(Colors color);

private:
    std::vector<std::shared_ptr<Pad>> m_pads;
    Colors m_color;
};
