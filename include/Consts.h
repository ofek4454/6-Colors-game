#pragma once

#include <SFML/Graphics.hpp>

const float WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height * 0.85;
const float WINDOW_WIDTH = WINDOW_HEIGHT*3/4;


const int NUM_OF_COLORS = 6;

const int NUM_OF_ROWS = 35;

const int NUM_OF_COLS = 30;

const float PAD_WIDTH = (WINDOW_WIDTH / (NUM_OF_ROWS))*0.6;
const float BUTTON_SIZE = WINDOW_WIDTH*0.05;


enum Colors {
    Yellow,
    Blue,
    Red,
    Orange,
    Green,
    Purple,
    NotAvailable
};

const sf::Color colors_arr[] = {sf::Color::Yellow,
                                sf::Color::Blue,
                                sf::Color::Red,
                                sf::Color(239, 120, 16),
                                sf::Color::Green,
                                sf::Color(176, 16, 239)};
