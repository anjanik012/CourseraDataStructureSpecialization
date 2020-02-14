#include <iostream>
#include <vector>

using std::vector;
using std::pair;

namespace graph {

    int cc;
    vector<bool> is_visited;

    void explore(const vector<vector<int>> &adj, const int v) {
        is_visited[v] = true;
        vector<int> neighbours = adj[v];
        for (auto &n: neighbours) {
            if (!is_visited[n])
                explore(adj, n);
        }
    }

    void DFS(const vector<vector<int>> &adj) {
        is_visited.resize(adj.size());
        for (int j = 0; j < adj.size(); ++j) {
            is_visited[j] = false;
        }
        cc = 0;
        for (auto &n : adj) {
            if (n.empty())
                cc++;

            for (auto &v : n) {
                if (!is_visited[v]) {
                    explore(adj, v);
                    cc++;
                }
            }
        }
    }

    int number_of_components(vector<vector<int> > &adj) {
        DFS(adj);
        return cc;
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
        adj[y - 1].push_back(x - 1);
    }
    std::cout << graph::number_of_components(adj);
}
