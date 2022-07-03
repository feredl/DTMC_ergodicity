#include "chain.hpp"


chain::chain() : size(0) {}

chain::chain(int s) : size(s) {}

chain::~chain() = default;  

void chain::set_size(int s) {
    this->size = s; 
};

int chain::get_size() {
    return this->size; 
};

bool chain::if_right_stochastic() {
    int counter = 0; 
    for (int i = 0; i < size; i++) {
        if (mx[i].if_stochastic()) {
            counter++; 
        } 
    }
    if (counter == size) {
        std::cout << "The matrix is stochastic." << std::endl;
        return true;
    }
    else {
        std::cout << "The matrix is not stochastic. Try again." << std::endl;
        return false;
    }
}; 

void chain::insert_probability() { 
    state st; 
    for (int i = 0; i < size; i++) {
        mx.push_back(st);
        mx[i].set_index(i);
        mx[i].insert_state_probability(size); 
    }
};

void chain::print() {
    for (int i = 0; i < mx.size(); i++) {
        mx[i].print_state(); 
    }
};

std::vector<std::vector<int>> chain::chain_to_vector() {
    std::vector<std::vector<int>> graph;  
    for (int i = 0; i < size; i++) {
        state st1 = mx[i];
        graph.push_back(st1.to_adjacent_vector(st1));
    }
    return graph; 
};

int chain::dijkstra_min_distance(std::vector<int> dist, std::vector<bool> spt_set, std::vector<std::vector<int>> graph)
{
    int min = INT_MAX;
    int min_index = 1231243;
    for (int v = 0; v < graph[0].size(); v++) {
        if (spt_set[v] == false && dist[v] <= min) {
            min = dist[v]; 
            min_index = v;
        }
    }
    return min_index;
}

std::vector<int> chain::dijkstra(std::vector<std::vector<int>> graph, int src) {
    std::vector<int> dist; 
    std::vector<bool> spt_set; 
    for (int i = 0; i < graph[0].size(); i++) {
        dist.push_back(10000);
        spt_set.push_back(false);
    }
    dist[src] = 0;
    for (int count = 0; count < graph[0].size() - 1; count++) {
        int u = dijkstra_min_distance(dist, spt_set, graph);
        spt_set[u] = true;
        for (int v = 0; v < graph[0].size(); v++) {
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist; 
}

std::vector<std::vector<int>> chain::full_dijkstra(std::vector<std::vector<int>> graph) {
    std::vector<std::vector<int>> res;
    for (int i = 0; i < graph[0].size(); i++) {
        res.push_back(dijkstra(graph, i)); 
    }
    return res;
};

bool chain::if_aperiodic() {
    int counter = 0; 
    for (int i = 0; i < size; i++) {
        if(mx[i].if_aperiodic()) {
            counter++; 
        } 
    }
    if (counter > 0) return true;
    else return false; 
}

bool chain::if_irreducible(std::vector<std::vector<int>> dijkstra_res) {
    int counter = 0; 
    for (int i = 0; i < dijkstra_res[0].size(); i++) {
        for (int j = 0; j < dijkstra_res[0].size(); j++) {
            if (dijkstra_res[i][j] == 0 && i != j || dijkstra_res[i][j] == 10000) {
                counter++;
            }
        }
    }
    if (counter == 0) return true; 
    else return false; 
}

bool chain::if_ergodic(bool aperiodic, bool communicating_and_essential) {
    if (aperiodic && communicating_and_essential) {
        return true;
    }
    else return false; 
};

