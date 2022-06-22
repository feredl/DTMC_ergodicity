#ifndef MARKOV_MATRIX_H
#define MARKOV_MATRIX_H

#include <vector>

class matrix {
private:
    int size;
    std::vector<std::vector<float>> mx;

public:
    matrix();
    ~matrix();

    void set_size(int size);
    int get_size(); 

    matrix insert_probability(float probability);
    bool if_right_stochastic();
    void print();

};


#endif //MARKOV_MATRIX_H
