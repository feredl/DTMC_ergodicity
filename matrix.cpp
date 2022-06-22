#include "matrix.h"

matrix::matrix() : size(0) {}

matrix::~matrix() = default;  

void matrix::set_size(int s) {
    this->size = s; 
}

int matrix::get_size() {
    return this->size; 
}

matrix matrix::insert_probability(float probability) {
    for (int i = 0; i < get_size(); ++i ) {
        for (int j = 0; j < get_size(); ++j ) {
            this->mx[i][j] = probability;
        }
    }
}

void matrix::print() {
    for (int i = 0; i < get_size(); i++) {
        for (int j = 0; j < get_size(); j++) {
            if (j == get_size() - 1){
                std::cout << mx[i][j] << std::endl;
            }
            else
                std::cout << mx[i][j] << "\t";
        }
    }
}

bool matrix::if_right_stochastic() {
    return false;
}
