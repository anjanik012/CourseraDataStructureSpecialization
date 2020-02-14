#include <iostream>
#include <vector>
#include <forward_list>

namespace graph {
    std::vector<bool> is_visited;
    std::forward_list<int> l_order;

    void explore(const std::vector<std::vector<int>> &adj, const int v) {
        is_visited[v] = true;
        std::vector<int> n = adj[v];
        if (n.empty())
            l_order.push_front(v + 1);
        else {
            for (auto &i: n) {
                if (!is_visited[i])
                    explore(adj, i);
            }
            l_order.push_front(v + 1);
        }
    }

    void DFS(const std::vector<std::vector<int>> &adj) {
        for (int i = 0; i < adj.size(); ++i) {
            if (!is_visited[i])
                explore(adj, i);
        }
    }

    std::forward_list<int> linear_order(const std::vector<std::vector<int>> &adj) {
        is_visited.resize(adj.size());
        for (int i = 0; i < adj.size(); ++i) {
            is_visited[i] = false;
        }
        DFS(adj);
        return l_order;
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
    }

    std::forward_list<int> ans = graph::linear_order(adj);
    for (auto &item: ans) {
        std::cout << item << ' ';
    }

    return 0;
}