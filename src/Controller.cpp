#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    "6Colors", sf::Style::Close | sf::Style::Titlebar), m_board(Board()) {
    m_board.create();
    createColorBtns();
}

void Controller::run() {
    printWindowObjects();
    while (m_window.isOpen()) {
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    for(auto btn : m_colorBtns)
                        if(btn.isPressed(event.mouseButton))
                            std::cout << btn.getColor() << std::endl;
                    break;

            }
        }
        printWindowObjects();
    }
}

void Controller::printWindowObjects() {
    m_window.clear();
    m_board.printBoardObject(m_window);
    for(auto btn : m_colorBtns)
        btn.draw(m_window);
    m_window.display();
}

void Controller::createColorBtns() {
    float pos_x = WINDOW_WIDTH*0.2;
    const float pos_y = WINDOW_HEIGHT- BUTTON_SIZE*4;

    for(int i=0 ; i<NUM_OF_COLORS ; i++){
        m_colorBtns[i] = ColorBtn(Colors(i), sf::Vector2f(pos_x,pos_y));
        pos_x += BUTTON_SIZE*2;
    }
}
