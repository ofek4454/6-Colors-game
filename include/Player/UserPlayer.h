#pragma once

#include "Player.h"

class UserPlayer : public Player {
public:
    UserPlayer();

    virtual Colors play(Colors color, Colors *lastChoosed);

};


