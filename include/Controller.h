#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"
#include "ColorBtn.h"
#include "RandomPlayer.h"
#include "UserPlayer.h"
#include "GreedyPlayerSmallDistance.h"

enum Turn{
    User,
    Other
};

class Controller {
public:
    Controller();
    void run();
private:
    void printWindowObjects();
    void createColorBtns();
    void playerTurn(Turn t, Colors color);
    void setLastColors(Colors color);

    sf::RenderWindow m_window;
    Board m_board;
    ColorBtn m_colorBtns[NUM_OF_COLORS];
    Colors m_lastChoosed[2];

    std::unique_ptr<Player> m_players[2];
};
