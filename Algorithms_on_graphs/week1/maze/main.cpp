#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> is_visited;

void explore(const vector<vector<int>> &adj, const int v) {
    is_visited[v] = true;
    vector<int> neighbours = adj[v];
    for (auto &n : neighbours) {
        if (!is_visited[n])
            explore(adj, n);
    }
}

int reach(const vector<vector<int> > &adj, const int u, const int v) {
    //write your code here
    explore(adj, u);
    return (is_visited[v]) ? 1 : 0;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    is_visited.resize(n);
    for (int j = 0; j < n; ++j) {
        is_visited[j] = false;
    }
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    std::cin >> x >> y;
    std::cout << reach(adj, x - 1, y - 1);
}
