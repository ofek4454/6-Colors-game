#pragma once

#include "Player.h"

class UserPlayer : public Player {
public:
    UserPlayer(std::shared_ptr<Pad> initial_pad);

    virtual void play(Colors color);

};


