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
    sf::Vector2f getPos() {return m_shape.getPosition();}
    Colors getColor();
    void setOutline(bool outline_on);
    std::array<std::shared_ptr<Pad>,NUM_OF_COLORS> *getNeighbor() {return &m_neighbors;}
    void setArray();
    void sumNeighborsColors(int arr[NUM_OF_COLORS], bool sumOthers = false);
    void setColor(Colors color);
    int getId() const {return m_id;}
    int checkExpansionSize(std::set<int> &checked_id, int &added);

private:
    int m_id;
    Colors m_color;
    bool m_isFree;
    sf::CircleShape m_shape;
    std::array<std::shared_ptr<Pad>,6> m_neighbors;
};
