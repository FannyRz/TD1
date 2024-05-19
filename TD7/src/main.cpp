#include <iostream>
#include <vector>
#include "graph.hpp"

void displayAdjencyList( Graph::WeightedGraph G){
    std::cout << "{" << std::endl;
    for(int i{0}; i<G.adjacency_list.size(); i++){
        std::cout <<"{" << i << ", {" ;
        for(Graph::WeightedGraphEdge edge : G.adjacency_list[i]){
            std::cout << "{" << edge.to << ", " << edge.weight << "}";
        }
        std::cout << "}}," << std::endl;
    }
    std::cout << "}" << std::endl;
}

int main(){

    std::unordered_map<int, std::vector<Graph::WeightedGraphEdge>> adjacency_list {
    {0, {{1, 1.0f}, {4, 2.0f}}},
    {1, {{2, 2.0f}, {3, 4.0f}}},
    {2, {{3, 1.0f}}},
    {3, {{4, 6.0f}}},
    {4, {}},
    };

    /*graphe 1*/

    Graph::WeightedGraph Graph1 {};
    
    std::vector<std::vector<float>> const& matrix{
        {0,1,0,0,2},
        {0,0,2,4,0},
        {0,0,0,1,0},
        {0,0,0,0,6},
        {0,0,0,0,0}
    };

    Graph1 = Graph::build_from_adjacency_matrix(matrix);
    std::cout << "Voici le liste d'adjacence du Graph1";
    // displayAdjencyList(Graph1);

    /*graphe 2*/

    Graph::WeightedGraph Graph2 {};

    Graph2.add_directed_edge(0,1,1);
    Graph2.add_directed_edge(0,4,2);
    Graph2.add_directed_edge(1,2,2);
    Graph2.add_directed_edge(1,3,4);
    Graph2.add_directed_edge(2,3,1);
    Graph2.add_directed_edge(3,4,6);

    std::cout << "Voici le liste d'adjacence du Graph2";
    // displayAdjencyList(Graph2);


    return 0;
}