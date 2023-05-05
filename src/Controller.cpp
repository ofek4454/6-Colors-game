#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    "6Colors", sf::Style::Close | sf::Style::Titlebar), m_board(Board()) {
    m_board.create();
}

void Controller::run() {
    printWindowObjects();
    while (m_window.isOpen()) {
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed: {
                    m_window.close();
                    break;
                }
            }
        }
        printWindowObjects();
    }
}

void Controller::printWindowObjects() {
    m_window.clear();
    m_board.printBoardObject(m_window);
    m_window.display();
}
