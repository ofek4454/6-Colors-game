//
// Created by Bar Kobi on 08/05/2023.
//
#include "typeinfo"
#include "UserPlayer.h"

UserPlayer::UserPlayer(std::shared_ptr<Pad> initial_pad) : Player(initial_pad) {

}

Colors UserPlayer::play(Colors color) {
    drawNeighbors(color);
    std::cout << "OWN : " << m_pads.size() << "\n";
    for(auto tmp : m_pads){
        std::cout << "ID : " << tmp->id << " neighbors: ";
        for(auto n : *tmp->getNeighbor()){
            if(n != NULL)
                std::cout << "n_ID: " << n->id << " , n_COLOR: " << n->getColor() << "\n";
        }
        std::cout << "\n";
    }
    return color;
}
