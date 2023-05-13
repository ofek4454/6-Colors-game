#include "typeinfo"
#include "UserPlayer.h"

UserPlayer::UserPlayer() : Player() {}

Colors UserPlayer::play(Colors color, Colors *lastChoosed) {
    drawNeighbors(color);
    return color;
}