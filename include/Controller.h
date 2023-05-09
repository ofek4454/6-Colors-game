#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "ColorBtn.h"
#include "RandomPlayer.h"
#include "UserPlayer.h"
#include "GreedyPlayerSmallDistance.h"
#include "GreedyPlayerLongDistance.h"
#include "string"

enum Turn{
    User,
    Other
};

class Controller {
public:
    Controller(sf::RenderWindow &window,std::unique_ptr<Player> *players);
    void run();
private:
    void printWindowObjects();
    void createColorBtns();
    void playerTurn(Turn t, Colors color);
    void setLastColors(Colors color);
    void handleHover(sf::Event::MouseMoveEvent &event);
    sf::RenderWindow &m_window;
    Board m_board;
    ColorBtn m_colorBtns[NUM_OF_COLORS];
    Colors m_lastChoosed[2];

    float m_scores[2] = {0.0f,0.0f};
    sf::Text m_texts[4];
    sf::Font m_font;
    std::string m_textNames[2] = {"<-","6Colors"};

    std::unique_ptr<Player> *m_players;

};
