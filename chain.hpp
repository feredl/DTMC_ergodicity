#pragma once

#include <vector>
#include <iostream>
#include "state.cpp"

class chain {
private:
    int size; //amount of states 
    std::vector<state> mx; //stochastic matrix

public:
    chain();
    chain(int size); 
    ~chain();

    void set_size(int size);
    int get_size(); 

    void insert_probability();
    bool if_right_stochastic();
    void print();
    std::vector<std::vector<int>> chain_to_vector();  
    void vector_print(std::vector<std::vector<int>> res);

    int dijkstra_min_distance(std::vector<int> dist, std::vector<bool> spt_set, std::vector<std::vector<int>> graph);
    std::vector<int> dijkstra(std::vector<std::vector<int>> graph, int src);
    std::vector<std::vector<int>> full_dijkstra(std::vector<std::vector<int>> graph);

    bool if_irreducible(std::vector<std::vector<int>> graph);
    bool if_aperiodic(); 

    bool if_ergodic(bool a, bool b); 
};