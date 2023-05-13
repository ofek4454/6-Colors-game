#pragma once
#include "Player.h"

class RandomPlayer : public Player{
public:
    RandomPlayer();
    virtual Colors play(Colors color, Colors *lastChoosed);
};

