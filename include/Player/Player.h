#pragma once
#include "set"
#include "Pad.h"

class Player{
public:
    Player();
    void setPad(GraphNode<std::shared_ptr<Pad>> new_pad);
    virtual Colors play(Colors color, Colors *lastChoosed) = 0;
    virtual ~Player() = default;
    int getNumOfPads();
    std::set<GraphNode<std::shared_ptr<Pad>>> *getPads() { return &m_pads;}
protected:
    std::set<GraphNode<std::shared_ptr<Pad>>> m_pads;
    void drawNeighbors(Colors color);
    Colors m_color;
private:
};