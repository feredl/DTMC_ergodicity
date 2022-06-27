#pragma once

#include <vector>
#include <iostream>
#include "state.hpp"

class chain {
private:
    int size; //amount of states 
    std::vector<state> mx; //

public:
    chain();
    chain(int size); 
    ~chain();

    void set_size(int size);
    int get_size(); 

    void insert_probability();
    void print();

    chain to_adjacency_mx(chain mx);
    bool if_right_stochastic();
    bool if_communicate(chain adjacency);
    bool if_ergodic(); 
};