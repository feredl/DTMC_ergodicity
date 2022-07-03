#include <iostream>
#include "chain.cpp"
#include "state.hpp"

using namespace std;

int main() {
    int n;
    std::cout << "Enter the amount of states in this markov chain>\t"; 
    std::cin >> n;
    chain mx(n);
    mx.insert_probability(); 
    mx.print();
    if (mx.if_right_stochastic()) {
        bool a = mx.if_irreducible(mx.full_dijkstra(mx.chain_to_vector()));
        bool b = mx.if_aperiodic();
        if (mx.if_ergodic(b, a)) {
            std::cout << "This Markov chain is ergodic. Final probabilities exist." << std::endl; 
        }
        else std::cout << "This Markov chain is not ergodic. Final probabilities do not exist." << std::endl;
    }
    else std::cout << "Try entering another probabilities." << std::endl;
    return 0;
}
