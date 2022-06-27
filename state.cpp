#include "state.hpp"
#include <iostream>

state::state() {};
state::~state() {}; 

void state::set_index(char id) {};
char state::get_index() {}; 
void state::set_state(std::vector<int> st) {}; 
std::vector<int> state::get_state() {}; 

void state::print_state() {}; 
void state::insert_state_probability(int probability) {};
std::vector<int> state::to_adjacency(std::vector<int> st) {};  

state path_length(state st1, state st2, state adjacent) {};
bool if_essential(state adjacent);
bool if_aperiodic(state adjacent);
