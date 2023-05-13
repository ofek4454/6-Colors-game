#pragma once
#include "Player.h"

class GreedyPlayerLongDistance : public Player{
public:
    GreedyPlayerLongDistance();
    virtual Colors play(Colors color, Colors *lastChoosed);
};

