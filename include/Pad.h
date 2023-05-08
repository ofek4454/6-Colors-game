#pragma once
#include "Consts.h"
#include "math.h"
#include "iostream"

class Pad {
public:
    Pad(int id,Colors color, sf::Vector2f pos,bool is_free = true);
    void draw(sf::RenderWindow &window);
    void uniteToGroup(const Colors color);
    bool isFree() const { return m_isFree;}
    sf::CircleShape getShape() {return m_shape;}
    Colors getColor();
    std::array<std::shared_ptr<Pad>,6> *getNeighbor() {return &m_neighbors;}
    void setArray();
private:
    bool m_isFree;
    Colors m_color;
    sf::CircleShape m_shape;
    std::array<std::shared_ptr<Pad>,6> m_neighbors;
    int id;
};
