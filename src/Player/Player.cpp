

#include "Player/Player.h"

Player::Player() {}

void Player::drawNeighbors(Colors color){
    m_color = color;
    for(GraphNode<std::shared_ptr<Pad>> pad: m_pads){
        auto united = pad.uniteToGroup(color);

        for (auto &tmp: united) {
            m_pads.insert(tmp);
        }
    }

}

void Player::setPad(GraphNode<std::shared_ptr<Pad>> new_pad) {
    m_pads.insert(new_pad);
    m_color = new_pad.getData()->getColor();
    auto setunited = new_pad.uniteToGroup(m_color);

    for(auto &tmp: setunited){
        m_pads.insert(tmp);
    }
}

int Player::getNumOfPads() {
    return m_pads.size();
}