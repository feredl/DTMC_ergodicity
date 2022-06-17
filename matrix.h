#ifndef MARKOV_MATRIX_H
#define MARKOV_MATRIX_H

#include <vector>

class matrix {
private:
    int size;
    
    std::vector<std::vector<float>> mx;
    bool if_correct(matrix m);
    matrix insert_probability(float probability);
    bool if_right_stochastic();
    matrix();
    ~matrix();
};


#endif //MARKOV_MATRIX_H
