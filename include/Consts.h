#pragma once

#include <SFML/Graphics.hpp>

const float WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height * 0.85;
const float WINDOW_WIDTH = WINDOW_HEIGHT*3/4;


const int NUM_OF_COLORS = 6;

const int NUM_OF_ROWS = 35;

const int NUM_OF_BUTTONS = 6;

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

const sf::Color colors_arr[] = {sf::Color(255,237,33),
                                sf::Color(45,170,237),
                                sf::Color(255,31,68),
                                sf::Color(255,148,33),
                                sf::Color(65,196,18),
                                sf::Color(133,43,237)};