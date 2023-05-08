//
// Created by Bar Kobi on 08/05/2023.
//

#include "UserPlayer.h"

UserPlayer::UserPlayer(std::shared_ptr<Pad> initial_pad) : Player(initial_pad) {

}

Colors UserPlayer::play(Colors color) {
    m_pads[0]->uniteToGroup(color);
}
