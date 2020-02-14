#include <iostream>
#include <vector>

using std::vector;
using std::pair;

namespace graph {

    bool is_cyclic = false;
    int temp = INT32_MIN;
    vector<bool> is_visited;

    void explore(const vector<vector<int>> &adj, const int v) {
        is_visited[v] = true;
        vector<int> n = adj[v];
        for (auto &i: n) {
            if (!is_visited[i])
                explore(adj, i);
            else{
                if (i == temp)
                    is_cyclic = true;
            }
        }
    }

    int acyclic(vector<vector<int> > &adj) {
        is_visited.resize(adj.size());
        for (int i = 0; i < adj.size(); ++i) {
            is_visited[i] = false;
        }

        for(int i = 0; i < adj.size() && !is_cyclic; ++i){
            vector<int> n = adj[i];
            is_visited[i] = true;
            temp = i;

            for(auto &v: n){
                if (!is_visited[v]) {
                    explore(adj, v);
                    if (is_cyclic)
                        break;
                }
            }
        }
        return (is_cyclic) ? 1 : 0;
    }
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << graph::acyclic(adj);
}
