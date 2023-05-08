#pragma once
#include "vector"
#include "Pad.h"

class Player{
public:
    Player(std::shared_ptr<Pad> initial_pad);
    virtual void play(Colors color) = 0;
protected:
    std::vector<std::shared_ptr<Pad>> m_pads;
private:
    Colors m_color;
};
