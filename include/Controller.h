#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "ColorBtn.h"
#include "RandomPlayer.h"
#include "UserPlayer.h"
#include "GreedyPlayerSmallDistance.h"
#include "GreedyPlayerLongDistance.h"
#include "string"
#include <sstream>
#include <iomanip>

enum Turn{
    User,
    Other
};

class Controller {
public:
    Controller(sf::RenderWindow &window,std::unique_ptr<Player> *players);
    void run();
private:
    void lightPads();
    void printWindowObjects();
    void createColorBtns();
    void playerTurn(Turn t, Colors color);
    void setLastColors(Colors color);
    void handleHover(sf::Event::MouseMoveEvent &event);
    void initTexts();

    sf::RenderWindow &m_window;
    Board m_board;
    ColorBtn m_colorBtns[NUM_OF_COLORS];
    Colors m_lastChoosed[2];
    float m_scores[2] = {0.0f,0.0f};
    sf::Text m_texts[4];
    sf::Text m_turnText;
    sf::Text m_gameOverText;
    std::string m_textNames[2] = {"<-","6Colors"};
    bool m_isGameOver = false;
    bool isTwoPlayers;
    std::unique_ptr<Player> *m_players;

};
