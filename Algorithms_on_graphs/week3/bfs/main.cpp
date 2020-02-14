#include <iostream>
#include <vector>
#include <queue>

namespace graph {

    std::vector<int> dist;

    void BFS(const std::vector<std::vector<int>> &adj, const int S) {
        dist.resize(adj.size());
        for (auto &item: dist) {
            item = INT32_MAX;
        }
        dist[S] = 0;
        std::queue<int> levels;
        levels.push(S);
        int u;
        while (!levels.empty()) {
            u = levels.front();
            levels.pop();
            std::vector<int> edges = adj[u];
            for (auto &v: edges) {
                if (dist[v] == INT32_MAX) {
                    levels.push(v);
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }

    int min_path(const std::vector<std::vector<int>> &adj, const int u, const int v) {
        BFS(adj, u);
        return (dist[v] != INT32_MAX) ? dist[v] : -1;
    }

}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n, std::vector<int>());
    int x, y;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    int ans = graph::min_path(adj, u, v);
    std::cout << ans;
    return 0;
}