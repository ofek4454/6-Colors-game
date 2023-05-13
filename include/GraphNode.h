#pragma once

#include <vector>
#include <memory>
#include <system_error>
#include "set"
#include "Consts.h"
#include "queue"

template <class T>
class GraphNode {
public:
    GraphNode(const T& data) : m_data(data){}
    std::vector<GraphNode*> getNeighbors() const { return m_neighbors; }
    T& getData() { return m_data; }
    void addEdge(GraphNode* neighbor) { m_neighbors.push_back(neighbor); }

    bool operator==(const GraphNode<T>& other) const {
        return this->m_data->getId() == other.m_data->getId();
    }

    bool operator!=(const GraphNode<T>& other) const {
        return m_data->getId()!= other.m_data->getId();
    }
    bool operator() (const GraphNode<T> lhs, const GraphNode<T> rhs) const
    {
        return lhs.m_data->getId() < rhs.m_data->getId();
    }
    bool operator<(const GraphNode<T>& other) const {
        return this->m_data->getId() < other.m_data->getId();
    }
    std::set<GraphNode<T>> uniteToGroup(const Colors color);
    void sumNeighborsColors(int arr[NUM_OF_COLORS], bool sumOthers = false);
    int checkExpansionSize(std::set<int> &checked_id, int &added);
private:
    std::vector<GraphNode*> m_neighbors;
    T m_data;
};

template<class T>
std::set<GraphNode<T>> GraphNode<T>::uniteToGroup(const Colors color) {
    std::set<GraphNode<T>> united;
    m_data->setFree(false);
    m_data->setColor(Colors(color));

    std::queue<GraphNode<T>> q;

    for (auto &pad: m_neighbors) {
        if (pad->getData() != NULL && pad->getData()->getColor() == m_data->getColor() && pad->getData()->isFree()) {
            q.push(*pad);
            united.insert(*pad);
        }
    }

    while (!q.empty()) {
        auto tmp = q.front();
        if (tmp.getData() == NULL) {
            q.pop();
            continue;
        }
        std::set<GraphNode<T>> added = tmp.uniteToGroup(color);
        for (auto tmp: added)
            united.insert(tmp);
        q.pop();
    }
    return united;
}

template<class T>
int GraphNode<T>::checkExpansionSize(std::set<int> &checked_id, int &added) {
    std::queue<GraphNode<T>> q;

    for (auto &pad: m_neighbors) {
        if (pad != NULL && pad->getColor() == m_data->getColor() && pad->isFree() && !checked_id.contains(m_data->getId())) {
            q.push(pad);
            checked_id.insert(pad->getId());
            added++;
        }
    }

    while (!q.empty()) {
        auto tmp = q.front();
        if (tmp == NULL) {
            q.pop();
            continue;
        }
        tmp->checkExpansionSize(checked_id, added);
        q.pop();
    }
    return added;
}

template<class T>
void GraphNode<T>::sumNeighborsColors(int *arr, bool sumOthers) {
    for (auto pad: m_neighbors)
        if (pad->getData() != NULL && pad->getData()->isFree()) {
            arr[pad->getData()->getColor()]++;
        }
}


