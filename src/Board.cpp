#include "Board.h"
#include "iostream"

void Board::create() {
    int x = 0;
    int y = 0;
    int row_i = 0;

    for (auto it = m_pads.begin(); it != m_pads.end(); ++it) {
        std::cout << *it << std::endl;
    }

//    for (auto &row: m_pads) {
//        int rand = std::rand() % NUM_OF_COLORS;
//        row = Pad(colors_arr[rand],sf::Vector2f(y,x));
//        y += PAD_WIDTH;
//        row_i++;
//    }
}

void Board::printBoardObject(sf::RenderWindow &window) {
    for (auto &it: m_pads) {
        it.draw(window);
    }
}
