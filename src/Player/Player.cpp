

#include "Player/Player.h"

Player::Player(std::shared_ptr<Pad> initial_pad) {
    m_pads.insert(initial_pad);
    m_color = initial_pad->getColor();
}

void Player::drawNeighbors(Colors color){
    m_color = color;
    for(auto &pad : m_pads){
        auto united = pad->uniteToGroup(color);

        for(auto &tmp : united)
            m_pads.insert(tmp);
    }

}