#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    "6Colors", sf::Style::Close | sf::Style::Titlebar), m_board(Board()) {
    m_board.create();
    auto tr = m_board.getTopRightCorner().get();
    m_lastChoosed[0] = tr->getColor();
    auto bl = m_board.getBottomLeftCorner().get();
    m_lastChoosed[1] = bl->getColor();
    createColorBtns();

}

void Controller::run() {
    static bool didPlayerChoose = false;
    printWindowObjects();
    while (m_window.isOpen()) {
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    for(auto btn : m_colorBtns)
                        if(btn.isPressed(event.mouseButton)){
                            didPlayerChoose = true;
                            std::cout << btn.getColor() << std::endl;
                        }
                    // TODO handle color choose
                    break;

            }
        }
        if(!didPlayerChoose)
            continue;
        else{
            playerTurn();
            didPlayerChoose = false;
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
        Colors color = Colors(i);
        bool disabled = color == m_lastChoosed[0] || color == m_lastChoosed[1];
        m_colorBtns[i] = ColorBtn(color, sf::Vector2f(pos_x,pos_y), disabled);
        pos_x += BUTTON_SIZE*2;
    }
}

void Controller::playerTurn() {

}
