#pragma once
#include "Player.h"

class GreedyPlayerSmallDistance : public Player{
public:
    GreedyPlayerSmallDistance();
    virtual Colors play(Colors color, Colors *lastChoosed);

};


