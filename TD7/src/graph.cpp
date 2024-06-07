#include "graph.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

void Graph::WeightedGraph::add_vertex(int const id){
    if(this->adjacency_list.find(id) == this->adjacency_list.end()){
        std::pair<int, std::vector<WeightedGraphEdge>> nouveau {id, {}};
        this->adjacency_list.insert(nouveau);
    }
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
    if(this->adjacency_list.find(from) == this->adjacency_list.end()){
        add_vertex(from);
    }
    if(this->adjacency_list.find(to) == this->adjacency_list.end()){
        add_vertex(to);
    }
    this->adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from,to,weight);
    add_directed_edge(to,from,weight);
}

Graph::WeightedGraph Graph::adjacency_list__from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
    Graph::WeightedGraph res {};
    for(int i {0}; i<adjacency_matrix.size(); i++){
        res.add_vertex(i);
        for(int j {0}; j<adjacency_matrix[i].size(); j++){
            if(adjacency_matrix[i][j] != 0){
                res.add_directed_edge(i,j,adjacency_matrix[i][j]);
            }
        }
    }
    return res;
}

bool estDedans (std::vector<int> tab, int entier){
    for(int i {0}; i<tab.size();i++){
        if(tab[i]==entier){
            return false;
        }
    }
    return true;
}

std::vector<int> Graph::WeightedGraph::DFS(int const start){
    std::stack<int> stack1 {};
    std::vector<int> res {};
    stack1.push(start);
    while(!(stack1.empty())){
        res.push_back(stack1.top());
        stack1.pop();
        
        for(WeightedGraphEdge element : adjacency_list[res[res.size()-1]]){
            stack1.push(element.to);
        }
    }
    return res;
}

void Graph::WeightedGraph::print_DFS(int const start){
    std::vector<int> list = DFS(start);
    std::cout << "[";
    for(int element : list){
        std::cout << element << ", ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> Graph::WeightedGraph::BFS(int const start){
    std::queue<int> queue1 {};
    std::vector<int> res {};
    queue1.push(start);
    while(!(queue1.empty())){
        res.push_back(queue1.front());
        queue1.pop();

        for(WeightedGraphEdge element : adjacency_list[res[res.size()-1]]){
            queue1.push(element.to);
        }
    }
    return res;
}

void Graph::WeightedGraph::print_BFS(int const start){
    std::vector<int> list = BFS(start);
    std::cout << "[";
    for(int element : list){
        std::cout << element << ", ";
    }
    std::cout << "]" << std::endl;
}