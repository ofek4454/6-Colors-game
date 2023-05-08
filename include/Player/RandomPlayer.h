#pragma once
#include "Player.h"

class RandomPlayer : public Player{
public:
    RandomPlayer(std::shared_ptr<Pad> initial_pad) : Player(initial_pad) {}
    virtual void play(Colors color){};
};


