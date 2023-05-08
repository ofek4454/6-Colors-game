#pragma once
#include "Consts.h"
#include "math.h"
#include "iostream"
#include "set"
#include "queue"

class Pad {
public:
    Pad(int id,Colors color, sf::Vector2f pos,bool is_free = true);
    void draw(sf::RenderWindow &window);
    std::set<std::shared_ptr<Pad>> uniteToGroup(const Colors color);
    bool isFree() const { return m_isFree;}
    sf::CircleShape getShape() {return m_shape;}
    Colors getColor();
    std::array<std::shared_ptr<Pad>,NUM_OF_COLORS> *getNeighbor() {return &m_neighbors;}
    void setArray();
    void sumNeighborsColors(int arr[NUM_OF_COLORS]);

    int id;

private:
    Colors m_color;
    bool m_isFree;
    sf::CircleShape m_shape;
    std::array<std::shared_ptr<Pad>,6> m_neighbors;
};
