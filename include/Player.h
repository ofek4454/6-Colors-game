#pragma once
#include "vector"
#include "Pad.h"

class Player{
public:
    Player(Colors color) : m_color(color){}
    void play(Colors color);

private:
    std::vector<std::shared_ptr<Pad>> m_pads;
    Colors m_color;
};
