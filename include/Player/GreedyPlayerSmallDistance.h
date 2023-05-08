#pragma once
#include "Player.h"

class GreedyPlayerSmallDistance : public Player{
public:
    GreedyPlayerSmallDistance(std::shared_ptr<Pad> initial_pad) : Player(initial_pad){}
    virtual void play(Colors color){};
};


