#include "Controller.h"
#include "UserPlayer.h"

Controller::Controller(sf::RenderWindow &window,std::unique_ptr<Player> *players) : m_window(window), m_board(Board()), m_players(players){

    m_board.create();
    auto tr = m_board.getTopRightCorner();
    m_lastChoosed[0] = tr->getColor();
    auto bl = m_board.getBottomLeftCorner();
    m_lastChoosed[1] = bl->getColor();
    m_players[0]->setPad(bl);
    m_players[1]->setPad(tr);
    createColorBtns();
    m_font.loadFromFile("../../../PressStart2P.ttf");
    int starting_y_scores = m_board.getTopRightCorner()->getPos().y - 20;
    int starting_x_scores = m_board.getBottomLeftCorner()->getPos().x + 20;
    int starting_x = 30;
    int starting_y = 30;

    for (int i = 0; i < 4;i++){
        m_texts[i].setFont(m_font);
        if(i < 2){
            m_texts[i].setCharacterSize(30);
            m_texts[i].setPosition(sf::Vector2f(starting_x,starting_y));
            m_texts[i].setFillColor(sf::Color::White);
            m_texts[i].setOutlineColor(sf::Color::Black);
            m_texts[i].setOutlineThickness(1);
            m_texts[i].setString(m_textNames[i]);
            starting_x = WINDOW_WIDTH /2 - m_texts[i].getGlobalBounds().width * 2;
            starting_y += m_texts[i].getGlobalBounds().height;
        }
        else{
            m_texts[i].setString(std::to_string(m_scores[i - 2]));
            m_texts[i].setCharacterSize(20);
            m_texts[i].setPosition(sf::Vector2f(starting_x_scores,starting_y_scores));
            starting_x_scores += PAD_WIDTH * NUM_OF_COLS * 1.33;
        }
    }

}

void Controller::run() {
    bool didPlayerChoose = false;
    Colors chosenColor;
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
                    if(m_texts[0].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y)){return;}
                    break;
                case sf::Event::MouseMoved:
                    handleHover(event.mouseMove);
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
    for(auto txt : m_texts)
        m_window.draw(txt);

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
    const Colors c = m_players[t]->play(color, m_lastChoosed);
    setLastColors(c);
}

void Controller::setLastColors(Colors color) {
    m_colorBtns[m_lastChoosed[1]].setDisabled(false);

    m_lastChoosed[1] = m_lastChoosed[0];
    m_lastChoosed[0] = color;

    m_colorBtns[color].setDisabled(true);

}

void Controller::handleHover(sf::Event::MouseMoveEvent &event) {
    if (m_texts[0].getGlobalBounds().contains(m_window.mapPixelToCoords({event.x, event.y}))) {
        m_texts[0].setOutlineThickness(2);
        m_texts[0].setOutlineColor(sf::Color::Red);
    } else {
        m_texts[0].setFillColor(sf::Color::White);
        m_texts[0].setOutlineThickness(0);
    }
    printWindowObjects();
}

