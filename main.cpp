#include <iostream>
#include "chain.cpp"
#include "state.hpp"

using namespace std;

void vector_print(std::vector<std::vector<int>> res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res.size(); j++) {
            if (j == res.size() - 1) { 
            std::cout << res[i][j] << std::endl; 
            }
            else std::cout << res[i][j] << "\t"; 
        }
    }
}

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
