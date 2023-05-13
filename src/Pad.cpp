#include "Pad.h"

Pad::Pad(int id, const int vertices, Colors color, sf::Vector2f pos, bool is_free)
        : m_id(id), m_color(color), m_shape(sf::CircleShape(PAD_WIDTH * (sqrt(3.f) / 2), vertices)), m_isFree(is_free) {
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
        if(tmp == NULL){
            q.pop();
            continue;
        }
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

void Pad::sumNeighborsColors(int *arr, bool sumOthers) {
    for(auto pad : m_neighbors)
        if(pad != NULL && pad->m_isFree){
            arr[pad->m_color]++;
        }
}

void Pad::setColor(Colors color) {
    m_color = color;
    m_shape.setFillColor(colors_arr[color]);
}

int Pad::checkExpansionSize(std::set<int> &checked_id, int &added) {
    std::queue<std::shared_ptr<Pad>> q;

    for(auto &pad : m_neighbors){
        if(pad != NULL && pad->m_color == m_color && pad->m_isFree && !checked_id.contains(m_id)){
            q.push(pad);
            checked_id.insert(pad->getId());
            added++;
        }
    }

    while(!q.empty()){
        auto tmp = q.front();
        if(tmp == NULL){
            q.pop();
            continue;
        }
        tmp->checkExpansionSize(checked_id, added);
        q.pop();
    }
    return added;
}
