#include "GreedyPlayerLongDistance.h"

GreedyPlayerLongDistance::GreedyPlayerLongDistance() : Player() {}

Colors GreedyPlayerLongDistance::play(Colors color, Colors *lastChoosed) {
    int count_colors[NUM_OF_COLORS] = {0};
    std::queue<GraphNode<std::shared_ptr<Pad>>> q;
    std::set<GraphNode<std::shared_ptr<Pad>>> s;

    count_colors[lastChoosed[0]] = (NUM_OF_ROWS * NUM_OF_COLS) * -1;
    count_colors[lastChoosed[1]] = (NUM_OF_ROWS * NUM_OF_COLS) * -1;
    q.push(*m_pads.begin());
    s.insert(*m_pads.begin());

    while (!q.empty()) {
        auto front = q.front();
        count_colors[front.getData()->getColor()]++;
        for (auto &neighbor: front.getNeighbors()) {
            if (neighbor->getData() && !s.contains(neighbor->getData()) &&
                (front.getData()->getColor() == m_color || front.getData()->getColor() == neighbor->getData()->getColor())) {
                q.push(neighbor->getData());
                s.insert(neighbor->getData());
            }
        }
        q.pop();
    }

    int *max = std::max_element(std::begin(count_colors), std::end(count_colors));
    int new_color = (int)(max - count_colors);
    drawNeighbors(Colors(new_color));
    return Colors(new_color);
}

// i want it with O(n) using dynamic programming
int calculate_fib(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return calculate_fib(n - 1) + calculate_fib(n - 2);
    }
}