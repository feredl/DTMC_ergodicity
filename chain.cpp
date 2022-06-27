#include "chain.hpp"

chain::chain() : size(0) {}

chain::chain(int s) : size(s) {}

chain::~chain() = default;  

void chain::set_size(int s) {
    this->size = s; 
}

int chain::get_size() {
    return this->size; 
}

void chain::insert_probability() {
    int probability;
    std::vector<int> temp; 
    for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            std::cout << "insert probability>\t"; 
            std::cin >> probability;
            temp.push_back(probability);
        }
        mx.push_back(temp);
        temp.clear();
    }
}

void chain::print() {
    for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            if (j == get_size() - 1){
                std::cout << mx[i][j] << std::endl;
            }
            else {
                std::cout << mx[i][j] << "\t";
            }
        }
    }
}

bool chain::if_right_stochastic() {
    int sum = 0;
    int flag;  
    for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            sum += mx[i][j];
        }
        if (sum != 100) {
            std::cout << "The matrix is not stochastic. Try again." << std::endl;
            return false;  
        }
        sum = 0; 
    }
    std::cout << "The matrix is stochastic." << std::endl;
    return true; 
}

chain chain::to_adjacency_mx(chain mx) {
    chain mx1 = mx;
    for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            if (mx1.mx[i][j] > 0) {
                mx1.mx[i][j] = 1; 
            }
        }
    }
    return mx1;
}
