#pragma once

#include "Board.h"
#include "Graph.h"
#include "Pad.h"

class HexagonBoard : public Board{
public:
    HexagonBoard() : Board(){};
    virtual void create() override;
    virtual void attachNeighbors() override;
    GraphNode<std::shared_ptr<Pad>> getBottomLeftCorner() {return m_graph.getNode((NUM_OF_COLS * NUM_OF_ROWS) - NUM_OF_COLS);}
    GraphNode<std::shared_ptr<Pad>> getTopRightCorner() { return m_graph.getNode((NUM_OF_COLS - 1));}
    sf::FloatRect getBoardBounds() {return m_overlay[4].getGlobalBounds();}
    void printBoardObject(sf::RenderWindow &window);

private:
    Graph<GraphNode<std::shared_ptr<Pad>>> m_graph;
};
