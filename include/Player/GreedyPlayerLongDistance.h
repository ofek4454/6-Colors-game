#pragma once
#include "Player.h"

class GreedyPlayerLongDistance : public Player{
public:
    GreedyPlayerLongDistance(std::shared_ptr<Pad> initial_pad);
    virtual void play(Colors color){};
};


