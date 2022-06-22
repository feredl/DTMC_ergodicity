#ifndef MARKOV_MATRIX_H
#define MARKOV_MATRIX_H

#include <vector>
#include <iostream>

class matrix {
private:
    int size;
    std::vector<std::vector<int>> mx;

public:
    matrix();
    matrix(int size); 
    ~matrix();

    void set_size(int size);
    int get_size(); 

    void insert_probability();
    bool if_right_stochastic();
    void print();

};


#endif //MARKOV_MATRIX_H