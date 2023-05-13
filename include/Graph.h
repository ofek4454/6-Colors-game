#pragma once

#include <vector>
#include <memory>
#include "GraphNode.h"

template <class T>
class Graph{
    public:
    void addNode(T node) {graph.push_back(node);}
    void addEdge(T* from, T* to) {
        from->addEdge(to);
    }
    std::vector<T>& getNodes() {return graph;}
    T& getNode(int index) {
        return graph.at(index);
    }
    T& operator[](int index) {
        return graph.at(index);
    }
private:
    std::vector<T> graph;
};