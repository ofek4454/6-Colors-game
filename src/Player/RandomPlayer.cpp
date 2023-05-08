//
// Created by Bar Kobi on 08/05/2023.
//

#include "RandomPlayer.h"

RandomPlayer::RandomPlayer(std::shared_ptr<Pad> initial_pad)
    : Player(initial_pad) {}

Colors RandomPlayer::play(Colors color){
    int new_color = std::rand() % NUM_OF_COLORS;
    drawNeighbors(Colors(new_color));

    return Colors(new_color);
}
