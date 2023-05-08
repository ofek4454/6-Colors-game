//
// Created by Ofek Gorgi on 07/05/2023.
//

#include "Player/Player.h"

Player::Player(std::shared_ptr<Pad> initial_pad) {
    m_pads.push_back(initial_pad);
    m_color = initial_pad->getColor();
}

void Player::drawNeighbors(Colors color){
    for(auto pad : m_pads){
        if(pad == NULL)
            continue;
        auto united = pad->uniteToGroup(color);
        for(auto tmp : united)
            m_pads.push_back(tmp);
    }
    m_color = color;
}