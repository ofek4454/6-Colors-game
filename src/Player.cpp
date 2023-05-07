//
// Created by Ofek Gorgi on 07/05/2023.
//

#include "Player.h"

Player::Player(std::shared_ptr<Pad> initial_pad) {
    m_pads.push_back(initial_pad);
    m_color = initial_pad->getColor();
}
