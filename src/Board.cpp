//
// Created by Bar Kobi on 12/05/2023.
//

#include "Board.h"

void Board::blur(sf::RenderWindow &window) {
    m_overlay[4].setFillColor(sf::Color(0, 0, 0, 180));
    window.draw(m_overlay[4]);
}

void Board::initOverlay(float starting_x, float starting_y, float width, float height) {
// overlay frame
    m_overlay[4].setSize(sf::Vector2f(width ,height));
    m_overlay[4].setPosition(starting_x+PAD_WIDTH*0.75+2,starting_y+PAD_WIDTH*0.5);
    m_overlay[4].setFillColor(sf::Color::Transparent);
    m_overlay[4].setOutlineColor(sf::Color::White);
    m_overlay[4].setOutlineThickness(2);

    // top overlay
    m_overlay[0].setSize(sf::Vector2f(WINDOW_WIDTH, starting_y+PAD_WIDTH*0.5));
    m_overlay[0].setPosition(sf::Vector2f(0,0));
    m_overlay[0].setFillColor(sf::Color(34,160,191));
    // left overlay
    m_overlay[1].setSize(sf::Vector2f(starting_x+PAD_WIDTH*0.75+2 , WINDOW_HEIGHT));
    m_overlay[1].setPosition(sf::Vector2f(0,0));
    m_overlay[1].setFillColor(sf::Color(34,160,191));
    // right overlay
    m_overlay[2].setSize(sf::Vector2f(starting_x+PAD_WIDTH*0.75+2, WINDOW_HEIGHT));
    m_overlay[2].setPosition(sf::Vector2f(starting_x+PAD_WIDTH*0.75+2+width,0));
    m_overlay[2].setFillColor(sf::Color(34,160,191));
    // bottom overlay
    m_overlay[3].setSize(sf::Vector2f(WINDOW_WIDTH, starting_y));
    m_overlay[3].setPosition(sf::Vector2f(0,starting_y+PAD_WIDTH*0.5 + height));
    m_overlay[3].setFillColor(sf::Color(34,160,191));

//    for(int i=0 ; i<4 ; i++)
//        m_overlay[i].setFillColor(sf::Color(34,160,191,100));
}
