#include <iostream>
#include "matrix.cpp"

using namespace std;

int main() {
    int size = 2; 
    matrix mx(size);
    cout << mx.get_size() << endl;
    mx.insert_probability(); 
    mx.print();
    mx.if_right_stochastic(); 
    return 0;
}
