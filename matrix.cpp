#include "matrix.hpp"

matrix::matrix() : size(0) {}

matrix::matrix(int s) : size(s) {}

matrix::~matrix() = default;  

void matrix::set_size(int s) {
    this->size = s; 
}

int matrix::get_size() {
    return this->size; 
}

void matrix::insert_probability() {
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

void matrix::print() {
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

bool matrix::if_right_stochastic() {
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
