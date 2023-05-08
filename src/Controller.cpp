#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                                    "6Colors", sf::Style::Close | sf::Style::Titlebar), m_board(Board()) {
    m_board.create();
    auto tr = m_board.getTopRightCorner();
    m_lastChoosed[0] = tr->getColor();
    auto bl = m_board.getBottomLeftCorner();
    m_lastChoosed[1] = bl->getColor();
    createColorBtns();

    m_players[0] = std::make_unique<UserPlayer>(bl);
    m_players[1] = std::make_unique<GreedyPlayerSmallDistance>(tr);

}

void Controller::run() {
    bool didPlayerChoose = false;
    Colors chosenColor;
    UserPlayer user_player(m_board.getBottomLeftCorner());
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
                            if(btn.getColor() != m_lastChoosed[0] && btn.getColor() != m_lastChoosed[1]){
                                didPlayerChoose = true;
                                chosenColor = btn.getColor();
                            }
                        }
                    // TODO handle color choose
                    break;

            }
        }
        if(!didPlayerChoose)
            continue;
        else{
            playerTurn(User, chosenColor);
            didPlayerChoose = false;
        }
        playerTurn(Other, chosenColor);
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
    const float pos_y = WINDOW_HEIGHT- BUTTON_SIZE*3;

    for(int i=0 ; i<NUM_OF_COLORS ; i++){
        Colors color = Colors(i);
        bool disabled = color == m_lastChoosed[0] || color == m_lastChoosed[1];
        m_colorBtns[i] = ColorBtn(color, sf::Vector2f(pos_x,pos_y), disabled);
        pos_x += BUTTON_SIZE*2;
    }
}

void Controller::playerTurn(Turn t, Colors color) {
    const Colors c = m_players[t]->play(color);
    setLastColors(c);
}

void Controller::setLastColors(Colors color) {
    m_colorBtns[m_lastChoosed[1]].setDisabled(false);

    m_lastChoosed[1] = m_lastChoosed[0];
    m_lastChoosed[0] = color;

    m_colorBtns[color].setDisabled(true);

}
