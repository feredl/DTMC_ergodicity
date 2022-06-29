#include "state.hpp"
#include <iostream>

state::state() : index(0) {}
state::state(char id) : index(id) {};
state::~state() = default;

void state::set_index(int index) {
    this->index = index; 
};

int state::get_index() {
    return index;
};

std::vector<int> state::get_state() {
    return st; 
}; 

void state::print_state() {
    for (int i = 0; i < st.size(); i++) {
        std::cout << st[i] << "\t"; 
    }
    std::cout << std::endl; 
}; 

void state::insert_state_probability(int size) { 
    int probability; 
    for (int i = 0; i < size; i++) {
        std::cout << "insert probability>\t"; 
        std::cin >> probability;
        st.push_back(probability);
    }
};

bool state::if_aperiodic() {
    int counter = 0; 
    for (int i = 0; i < st.size(); i++) {
        if (st[i] > 0) {
            counter++; 
        }
    }
    if (st[index] > 0 || counter == st.size()-1) {
        return true;
    }
    else return false;
};

bool state::if_stochastic() {
    int sum = 0; 
    for (int i = 0; i < st.size(); i++) {
        sum += st[i];
    }
    if (sum == 100) {
        return true; 
    }
    else return false; 
};

std::vector<int> state::to_adjacent_vector(state st1) {
    std::vector<int> new_st; 
    for (int i = 0; i < st1.st.size(); i++) {
        if (st1.st[i] > 0) {
            st1.st[i] = 1; 
        }
    }
    new_st = st1.st;
    return new_st; 
};
