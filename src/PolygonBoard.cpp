
#include "PolygonBoard.h"

void PolygonBoard::create() {
    srand(time(NULL));
    const float total_width = ((PAD_WIDTH * 1.5) + 4) * (NUM_OF_COLS - 0.5);
    const float starting_x = WINDOW_WIDTH / 2 - total_width / 2 - ((PAD_WIDTH * 1.5) + 4) / 2;

    const float total_height = (PAD_WIDTH * 1.5) * (NUM_OF_ROWS - 0.5);
    const float starting_y = WINDOW_HEIGHT / 2 - total_height / 2;

    int i = 0;
    float x = starting_x, y = starting_y;
    for (int row = 0; row < NUM_OF_ROWS; row++, y += PAD_WIDTH * 1.5) {
        for (int col = 0; col < NUM_OF_COLS; col++, x += (PAD_WIDTH * 1.5) + 4) {
            int rand = std::rand() % NUM_OF_COLORS;
            auto pad = std::make_shared<Pad>(i,4, Colors(rand), sf::Vector2f(x, y));
            m_graph.addNode(GraphNode<std::shared_ptr<Pad>>(pad));
            i++;
        }
        x = row % 2 == 0 ? (PAD_WIDTH * 0.75) + 2 : 0;
        x += starting_x;
    }

    while (getTopRightCorner().getData()->getColor() == getBottomLeftCorner().getData()->getColor()) {
        int rand = std::rand() % NUM_OF_COLORS;
        getTopRightCorner().getData()->setColor(Colors(rand));
    }

    initOverlay(starting_x, starting_y, total_width, total_height);

    attachNeighbors();
}

void PolygonBoard::attachNeighbors() {
    std::vector<sf::Vector2u> odd_neighbors{
            sf::Vector2u(1, 0),
            sf::Vector2u(-1, 0),
            sf::Vector2u(0, -1),
            sf::Vector2u(1, -1),
            sf::Vector2u(0, 1),
            sf::Vector2u(1, 1)
    };
    std::vector<sf::Vector2u> even_neighbors{
            sf::Vector2u(1, 0),
            sf::Vector2u(-1, 0),
            sf::Vector2u(0, -1),
            sf::Vector2u(-1, -1),
            sf::Vector2u(0, 1),
            sf::Vector2u(-1, 1)
    };
    auto tmp_odd = odd_neighbors;
    auto tmp_even = even_neighbors;
    for (int i = 0; i < (NUM_OF_COLS * NUM_OF_ROWS); i++) {

        int x = i % NUM_OF_COLS;
        int y = i / NUM_OF_COLS;
        if (y % 2 == 0) {
            for (sf::Vector2u &neighbor: tmp_even) {
                neighbor += sf::Vector2u(x, y);
                if (neighbor.x >= 0 && neighbor.x < NUM_OF_COLS && neighbor.y >= 0 && neighbor.y < NUM_OF_ROWS) {
                    m_graph.addEdge(&m_graph.getNode(i), &m_graph.getNode(neighbor.x + neighbor.y * NUM_OF_COLS));
                }
            }
        } else {
            for (sf::Vector2u &neighbor: tmp_odd) {
                neighbor += sf::Vector2u(x, y);
                if (neighbor.x >= 0 && neighbor.x < NUM_OF_COLS && neighbor.y >= 0 && neighbor.y < NUM_OF_ROWS) {
                    m_graph.addEdge(&m_graph.getNode(i), &m_graph.getNode(neighbor.x + neighbor.y * NUM_OF_COLS));
                }
            }
        }
        tmp_even = even_neighbors;
        tmp_odd = odd_neighbors;
    }

}

void PolygonBoard::printBoardObject(sf::RenderWindow &window) {
    for (auto &it: m_graph.getNodes()) {
        it.getData()->draw(window);
    }
    for (int i = 0; i < 5; i++)
        window.draw(m_overlay[i]);
}

