//
// Created by Bar Kobi on 05/05/2023.
//

#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "6Colors", sf::Style::Close | sf::Style::Titlebar){

}

void Controller::run() {
    while(m_window.isOpen()){

    }
}

void Controller::printWindowObjects() {
    m_window.clear();
}
