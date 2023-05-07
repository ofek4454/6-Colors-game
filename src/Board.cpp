#include "Board.h"
#include "iostream"

void Board::create() {
    const float total_width = ((PAD_WIDTH*1.5)+4)*(NUM_OF_COLS-0.5) ;
    const float starting_x = (WINDOW_WIDTH-total_width)/2;

    const float total_height = (PAD_WIDTH*1.5)*(NUM_OF_ROWS-0.5);
    const float starting_y = (WINDOW_HEIGHT-total_height)/2;

    int i=0;
    float x = starting_x, y = starting_y;
    for (int row = 0; row < NUM_OF_ROWS; row++, y+=PAD_WIDTH*1.5) {
        auto padrow = Mosaic<std::shared_ptr<Pad>>();
        m_pads.add(padrow);
        for (int col = 0; col < NUM_OF_COLS; col++, x += (PAD_WIDTH * 1.5) + 4) {
            int rand = std::rand() % NUM_OF_COLORS;
            auto pad = std::make_shared<Pad>(i, Colors(rand), sf::Vector2f(x, y));
            pad->setArray();
            m_pads[row].add(pad);
            i++;
        }
        x = row % 2 == 0 ? (PAD_WIDTH * 0.75) + 2 : 0;
        x += starting_x;
    }

    initOverlay(starting_x, starting_y, total_width, total_height);

    attachNeighbors();
}

void Board::initOverlay(float starting_x, float starting_y, float width, float height) {
    const float rectWidth = width; //width*0.75 + 4*NUM_OF_COLS + starting_x + (PAD_WIDTH*2*0.75 + 2);
    const float rectHeight = height; //height*0.75 + 4*NUM_OF_ROWS - (PAD_WIDTH*0.75)+ 2;

    // overlay frame
    m_overlay[4].setSize(sf::Vector2f(rectWidth ,rectHeight));
    m_overlay[4].setPosition(starting_x+PAD_WIDTH*0.75+2,starting_y+PAD_WIDTH*0.5);
    m_overlay[4].setFillColor(sf::Color::Transparent);
    m_overlay[4].setOutlineColor(sf::Color::White);
    m_overlay[4].setOutlineThickness(2);

    // top overlay
    m_overlay[0].setSize(sf::Vector2f(WINDOW_WIDTH, starting_y+PAD_WIDTH*0.5));
    m_overlay[0].setPosition(sf::Vector2f(0,0));
    m_overlay[0].setFillColor(sf::Color::Black);
    // left overlay
    m_overlay[1].setSize(sf::Vector2f(starting_x+PAD_WIDTH*0.75+2 , WINDOW_HEIGHT));
    m_overlay[1].setPosition(sf::Vector2f(0,0));
    m_overlay[1].setFillColor(sf::Color::Black);
    // right overlay
    m_overlay[2].setSize(sf::Vector2f(starting_x+PAD_WIDTH*0.75+2, WINDOW_HEIGHT));
    m_overlay[2].setPosition(sf::Vector2f(starting_x+PAD_WIDTH*0.75+2+rectWidth,0));
    m_overlay[2].setFillColor(sf::Color::Black);
    // bottom overlay
    m_overlay[3].setSize(sf::Vector2f(WINDOW_WIDTH, starting_y));
    m_overlay[3].setPosition(sf::Vector2f(0,starting_y+PAD_WIDTH*0.5 + rectHeight));
    m_overlay[3].setFillColor(sf::Color::Black);

//    for (int i = 0; i < 5; i++){
//        m_overlay[i].setFillColor(sf::Color(255,255,255,100));
//    }
}

std::shared_ptr<Pad> Board::getBottomLeftCorner() {
    return m_pads[NUM_OF_ROWS - 1][0];
}

std::shared_ptr<Pad> Board::getTopRightCorner() {
    return m_pads[0][NUM_OF_COLS-1];
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
            auto arr_neighbors = m_pads[row][col]->getNeighbor();
            auto it = arr_neighbors->begin();
            if (row == 0) {
                if (col != 0) {
                    *it = m_pads[row][col-1];
                    it++;
                    *it = m_pads[row + 1][col - 1];
                    it++;
                }
                *it = m_pads[row + 1][col];
                it++;
                if (col != NUM_OF_COLS - 1) {
                    *it = m_pads[row][col + 1];
                }
            } else if (row == NUM_OF_ROWS - 1) {
                if (col != 0) {
                    *it = m_pads[row - 1][col - 1];
                    it++;
                    *it = m_pads[row][col - 1];
                    it++;
                }
                *it = m_pads[row - 1][col];
                it++;
                if (col != NUM_OF_COLS - 1){
                    *it = m_pads[row][col + 1];
                }
            } else {
                if (col != 0) {
                    *it = m_pads[row][col - 1];
                    it++;
                }
                *it = m_pads[row + 1][col];
                it++;
                *it = m_pads[row - 1][col];
                it++;
                if (col != NUM_OF_COLS - 1) {
                    *it = m_pads[row][col + 1];
                    it++;
                    *it = m_pads[row - 1][col + 1];
                    it++;
                    *it = m_pads[row + 1][col + 1];
                }
            }
        }
    }
}
