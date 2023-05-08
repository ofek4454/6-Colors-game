#pragma once
#include "Player.h"
#include "set"

class GreedyPlayerSmallDistance : public Player{
public:
    GreedyPlayerSmallDistance(std::shared_ptr<Pad> initial_pad);
    virtual Colors play(Colors color) override;
};


