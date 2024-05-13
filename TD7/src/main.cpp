#include <iostream>
#include <vector>
#include "graph.hpp"

int main(){

    std::unordered_map<int, std::vector<Graph::WeightedGraphEdge>> adjacency_list {
        {0, {{1, 1.0f}, {4, 2.0f}}},
        {1, {{2, 2.0f}, {3, 4.0f}}},
        {2, {{3, 1.0f}}},
        {3, {{4, 6.0f}}},
        {4, {}},
    };

    return 0;
}