#include "Board.h"
#include "iostream"
#include "memory"

void Board::create() {
    const int total_width = ((PAD_WIDTH * 2 * 0.75) + 4) * NUM_OF_COLS;
    const int starting_x = (WINDOW_WIDTH - total_width) / 2;

    const int total_height = ((PAD_WIDTH * 2 * 0.75) + 4) * NUM_OF_ROWS;
    const int starting_y = (WINDOW_HEIGHT - total_height) / 2;

    int x = starting_x, y = starting_y;
    for (int row = 0; row < NUM_OF_ROWS; row++, y += PAD_WIDTH * 2 * 0.75) {
        auto padrow = Mosaic<std::shared_ptr<Pad>>();
        m_pads.add(padrow);
        for (int col = 0; col < NUM_OF_COLS; col++, x += (PAD_WIDTH * 2 * 0.75) + 4) {
            int rand = std::rand() % NUM_OF_COLORS;
            auto pad = std::make_shared<Pad>(colors_arr[rand], sf::Vector2f(x, y));
            m_pads[row].add(pad);
        }
        x = row % 2 == 0 ? (PAD_WIDTH * 0.75) + 2 : 0;
        x += starting_x;
    }

    m_overlay[0].setSize(sf::Vector2f(WINDOW_WIDTH, starting_y + PAD_WIDTH * 0.5));
    m_overlay[0].setPosition(sf::Vector2f(0, 0));
    m_overlay[0].setFillColor(sf::Color::Black);
    m_overlay[1].setSize(sf::Vector2f(starting_x + PAD_WIDTH * 0.75 + 2, WINDOW_HEIGHT));
    m_overlay[1].setPosition(sf::Vector2f(0, 0));
    m_overlay[1].setFillColor(sf::Color::Black);
    m_overlay[2].setSize(sf::Vector2f(starting_x + PAD_WIDTH * 0.75 + 2, WINDOW_HEIGHT));
    m_overlay[2].setPosition(sf::Vector2f(WINDOW_WIDTH - starting_x - PAD_WIDTH * 0.75 - 2, 0));
    m_overlay[2].setFillColor(sf::Color::Black);
    m_overlay[3].setSize(sf::Vector2f(WINDOW_WIDTH, starting_y));
    m_overlay[3].setPosition(sf::Vector2f(0, total_height + PAD_WIDTH * 0.75 + 2));
    m_overlay[3].setFillColor(sf::Color::Black);

    m_overlay[4].setSize(sf::Vector2f(total_width * 0.75 + 4 * NUM_OF_COLS + starting_x + (PAD_WIDTH * 2 * 0.75),
                                      total_height * 0.75 + 4 * NUM_OF_ROWS - (PAD_WIDTH * 0.75 + 2)));
    m_overlay[4].setPosition(starting_x + PAD_WIDTH * 0.75 + 2, starting_y + PAD_WIDTH * 0.5);
    m_overlay[4].setFillColor(sf::Color::Transparent);
    m_overlay[4].setOutlineColor(sf::Color::White);
    m_overlay[4].setOutlineThickness(2);

    attachNeighbors();
}

void Board::printBoardObject(sf::RenderWindow &window) {
    for (auto &it: m_pads) {
        for (auto &val: it) {
            val->draw(window);
        }
    }
    for (int i = 0; i < 5; i++)
        window.draw(m_overlay[i]);
}

void Board::attachNeighbors() {
    for (int row = 0; row < NUM_OF_ROWS; row++) {
        for (int col = 0; col < NUM_OF_COLS; col++) {
            auto tmp = m_pads[0][0]->getNeighbor();
            if (row == 0) {
                tmp[col].begin()->reset(m_pads[row + 1][col].get());
                /*
                if (col != NUM_OF_COLS - 1)
                    tmp[col].begin()->reset(m_pads[row - 1][col + 1].get());
                if (col != 0)
                    tmp[col].begin()->reset(m_pads[row - 1][col - 1].get());
            } else if (row == NUM_OF_ROWS - 1) {
                tmp[col].begin()->reset(m_pads[row + 1][col].get());
                if (col != NUM_OF_COLS - 1)
                    tmp[col].begin()->reset(m_pads[row + 1][col + 1].get());
                if (col != 0)
                    tmp[col].begin()->reset(m_pads[row + 1][col - 1].get());
            } else {
                tmp[col].begin()->reset(m_pads[row + 1][col].get());
                tmp[col].begin()->reset(m_pads[row - 1][col].get());
                if (col != NUM_OF_COLS - 1) {
                    tmp[col].begin()->reset(m_pads[row - 1][col + 1].get());
                    tmp[col].begin()->reset(m_pads[row + 1][col + 1].get());
                }
                if (col != 0) {
                    tmp[col].begin()->reset(m_pads[row - 1][col - 1].get());
                    tmp[col].begin()->reset(m_pads[row + 1][col - 1].get());
                }
*/

            }
        }
    }
}
