#include "Pad.h"

Pad::Pad(int id, Colors color, sf::Vector2f pos, bool is_free)
        : id(id), m_color(color), m_shape(sf::CircleShape(PAD_WIDTH * (sqrt(3.f) / 2), 6)), m_isFree(is_free) {
    m_shape.setFillColor(colors_arr[color]);
    m_shape.setPosition(pos);
    m_shape.setOutlineColor(sf::Color::White);
    m_shape.setOutlineThickness(.5);
}

std::set<std::shared_ptr<Pad>> Pad::uniteToGroup(const Colors color) {
    std::set<std::shared_ptr<Pad>> united;
    m_isFree = false;
    m_shape.setFillColor(colors_arr[color]);
    m_color = color;

    std::queue<std::shared_ptr<Pad>> q;

    for(auto &pad : m_neighbors){
        if(pad != NULL && pad->m_color == m_color && pad->m_isFree){
            q.push(pad);
            united.insert(pad);
        }
    }

    while(!q.empty()){
        auto tmp = q.front();
        std::set<std::shared_ptr<Pad>> added = tmp->uniteToGroup(color);
        for(auto tmp : added)
            united.insert(tmp);
        q.pop();
    }
    return united;
}

void Pad::draw(sf::RenderWindow &window) { window.draw(m_shape); }

Colors Pad::getColor() {
    return m_color; }

void Pad::setArray() {
    m_neighbors.fill(nullptr);
}

void Pad::sumNeighborsColors(int *arr) {
    for(auto pad : m_neighbors)
        if(pad != NULL && pad->m_isFree)
            arr[pad->m_color]++;
}