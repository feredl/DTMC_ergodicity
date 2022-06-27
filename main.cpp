#include <iostream>
#include "chain.cpp"

using namespace std;

int main() {
    int size = 2; 
    chain mx(size);
    cout << mx.get_size() << endl;
    mx.insert_probability(); 
    mx.print();
    mx.if_right_stochastic();
    chain mx1(size);
    mx1 = mx.to_adjacency_mx(mx);
    mx1.print(); 
    return 0;
}
