#include <iostream>
#include <vector>

namespace graph {
    std::vector<int> dist;

    void bellman_ford(const std::vector<std::vector<std::pair<int, int>>> &adj, int S) {
        int V = adj.size();
        dist.resize(V);
        for (int i = 0; i < V; ++i) {
//            dist[i] = 1001;
            dist[i] = 0;
        }
//        dist[S] = 0;
        for (int i = 1; i <= V - 1; ++i) {
            for (int u = 0; u < V; ++u) {
                for (auto &p : adj[u]) {
                    int v = p.first;
                    int w = p.second;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
    }

    int is_negative_cycle(const std::vector<std::vector<std::pair<int, int>>> &adj, int S) {
        bellman_ford(adj, S);
//        for (auto x : dist) {
//            std::cout << x << " ";
//        }
//        std::cout << std::endl;
        bool to_break = false;
        for (int u = 0; u < adj.size(); ++u) {
            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;
                if (dist[v] > dist[u] + w) {
                    to_break = true;
                }
                if (to_break) {
                    break;
                }
            }
            if (to_break) {
                break;
            }
        }
        return (to_break) ? 1 : 0;
    }
}


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n, std::vector<std::pair<int, int>>());
    int x, y, z;
    for (int i = 0; i < m; ++i) {
        std::cin >> x >> y >> z;
        adj[x - 1].push_back(std::make_pair(y - 1, z));
    }
    std::cout << graph::is_negative_cycle(adj, 0) << std::endl;
    return 0;
}