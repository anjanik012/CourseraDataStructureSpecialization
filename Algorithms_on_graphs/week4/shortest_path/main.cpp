#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::pair;
using std::cout;
using std::cin;

namespace graph {
    vector<int> dist;

    void dijkstra(vector<vector<pair<int, int>>> &adj, int S) {
        dist.resize(adj.size());
        for (auto &i: dist) {
            i = INT32_MAX;
        }
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        dist[S] = 0;
        pq.push(std::make_pair(S, 0));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            vector<pair<int, int>> n = adj[u];
            for (auto &i: n) {
                int v = i.first;
                int w = i.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }
    }

    int shortest_path(vector<vector<pair<int, int>>> &adj, int S, int t) {
        dijkstra(adj, S);
        return (dist[t] != INT32_MAX) ? dist[t] : -1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    int x, y, z;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        adj[x - 1].push_back(std::make_pair(y - 1, z));
    }
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cout << graph::shortest_path(adj, u, v) << std::endl;
    return 0;
}