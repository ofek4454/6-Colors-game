#pragma once
#include "Player.h"

class RandomPlayer : public Player{
public:
    RandomPlayer(std::shared_ptr<Pad> initial_pad);
    virtual Colors play(Colors color) override{}
};


