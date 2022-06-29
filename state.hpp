#pragma once 

#include <vector>
#include <iostream>

class state {
private:
    int index; 
    std::vector<int> st; 

public:
    state();
    state(char id);
    ~state(); 

    void set_index(int index);
    int get_index(); 
    void set_state(std::vector<int> st); 
    std::vector<int> get_state();

    void print_state(); 
    void insert_state_probability(int size);
    std::vector<int> to_adjacent_vector(state st1);
    bool if_aperiodic(); 
    bool if_stochastic(); 
};
