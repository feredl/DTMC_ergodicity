#include <iostream>
#include "matrix.cpp"

int main() {
    matrix mx;
    mx.set_size(2);
    float probability; 
    std::cin >> probability; 
    mx.insert_probability(probability); 
    mx.print();  
    return 0;
}
