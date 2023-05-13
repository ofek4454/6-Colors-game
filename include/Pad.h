#pragma once
#include "Consts.h"
#include "math.h"
#include "iostream"
#include "set"
#include "queue"
#include "Graph.h"

class Pad {
public:
    Pad(int id,const int vertices,Colors color, sf::Vector2f pos,bool is_free = true);
    void draw(sf::RenderWindow &window);
    bool isFree() const { return m_isFree;}
    void setFree(bool is_free) { m_isFree = is_free;}
    sf::CircleShape getShape() {return m_shape;}
    sf::Vector2f getPos() {return m_shape.getPosition();}
    Colors getColor();
    void setOutline(bool outline_on);
    void setColor(Colors color);
    int getId() const {return m_id;}

private:
    int m_id;
    Colors m_color;
    bool m_isFree;
    sf::CircleShape m_shape;
};