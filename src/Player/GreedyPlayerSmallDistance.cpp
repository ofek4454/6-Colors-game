//
// Created by Bar Kobi on 08/05/2023.
//

#include "GreedyPlayerSmallDistance.h"

GreedyPlayerSmallDistance::GreedyPlayerSmallDistance(std::shared_ptr<Pad> initial_pad)
    : Player(initial_pad) {}

Colors GreedyPlayerSmallDistance::play(Colors color) {
    int count_colors[NUM_OF_COLORS] = {0};

    for(auto pad : m_pads)
        pad->sumNeighborsColors(count_colors);

    int *max = std::max_element(std::begin(count_colors), std::end(count_colors));

    drawNeighbors(Colors(*max));
    return Colors(*max);

}