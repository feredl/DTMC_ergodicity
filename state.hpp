#pragma once 

#include <vector>
#include <iostream>

class state {
private:
    char index; 
    std::vector<int> st; 

public:
    state();
    ~state(); 

    void set_index(char index);
    char get_index(); 
    void set_state(std::vector<int> st); 
    std::vector<int> get_state();

    void print_state(); 
    void insert_state_probability(int probability);
    std::vector<int> to_adjacency(std::vector<int> st);  

    state path_length(state st1, state st2, chain adjacency);
    bool if_essential(chain adjacency);
    bool if_aperiodic(chain adjacency); 
};
