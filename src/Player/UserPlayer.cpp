//
// Created by Bar Kobi on 08/05/2023.
//
#include "typeinfo"
#include "UserPlayer.h"

UserPlayer::UserPlayer(std::shared_ptr<Pad> initial_pad) : Player(initial_pad) {}

Colors UserPlayer::play(Colors color, Colors *lastChoosed) {
    drawNeighbors(color);

    std::cout << std::endl;
    return color;
}
