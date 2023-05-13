//
// Created by Bar Kobi on 08/05/2023.
//

#include "RandomPlayer.h"

RandomPlayer::RandomPlayer()
        : Player() {}

Colors RandomPlayer::play(Colors color, Colors *lastChoosed){
    int new_color;
    do{
        new_color = std::rand() % NUM_OF_COLORS;
    }while(new_color == lastChoosed[0] || new_color == lastChoosed[1]);

    drawNeighbors(Colors(new_color));
    return Colors(new_color);
}