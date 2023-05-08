//
// Created by Bar Kobi on 08/05/2023.
//

#include "GreedyPlayerSmallDistance.h"

GreedyPlayerSmallDistance::GreedyPlayerSmallDistance(std::shared_ptr<Pad> initial_pad) : Player(initial_pad) {}

Colors GreedyPlayerSmallDistance::play(Colors color){
    std::set<std::shared_ptr<Pad>> counted_pads;
    int sum_of_colors[NUM_OF_COLORS] = {0};
    for(auto &pad : m_pads){
        auto neighbors = pad->getNeighbor();
        for(auto &neighbor : *neighbors){
            if(neighbor != NULL && !counted_pads.contains(neighbor)){
                sum_of_colors[neighbor->getColor()]++;
                counted_pads.insert(neighbor);
            }
        }
    }
    auto max = std::max_element(std::begin(sum_of_colors),std::end(sum_of_colors));
    std::cout << *max;

    return Colors(*max);
}
