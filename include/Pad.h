#pragma once
#include "Consts.h"
#include "math.h"

class Pad {
public:
    Pad(int id, Colors color, sf::Vector2f pos,bool is_free = true);
    void draw(sf::RenderWindow &window);
    void uniteToGroup(const sf::Color color);
    bool isFree() const { return m_isFree;}
    sf::CircleShape getShape() {return m_shape;}
    Colors getColor();
    int getId(){return id;}

    std::array<std::shared_ptr<Pad>,6> *getNeighbor() {return &m_neighbors;}
//    std::shared_ptr<Pad> *getNeighbor(int index) {return &m_neighbors[index];}
private:
    int id;
    bool m_isFree;
    Colors m_color;
    sf::CircleShape m_shape;
    std::array<std::shared_ptr<Pad>,6> m_neighbors;
};
