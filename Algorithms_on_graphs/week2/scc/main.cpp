#include <iostream>
#include <vector>
#include <algorithm>

namespace graph {
    std::vector<bool> is_visited, is_visited_r;
    int clock;
    std::vector<int> pre_visit, post_visit;

    std::vector<std::vector<int>> reverse_graph(const std::vector<std::vector<int>> &adj) {
        std::vector<std::vector<int>> r_graph(adj.size(), std::vector<int>());
        std::vector<int> n;
        for (int i = 0; i < adj.size(); ++i) {
            n = adj[i];
            for (auto &v: n) {
                r_graph[v].push_back(i);
            }
        }
        return r_graph;
    }

    void pre_order(const int v) {
        pre_visit[v] = clock;
        clock++;
    }

    void post_order(const int v) {
        post_visit[v] = clock;
        clock++;
    }

    void explore_r(const std::vector<std::vector<int>> &adj, const int v) {
        is_visited_r[v] = true;
        pre_order(v);
        std::vector<int> n = adj[v];
        for (auto &i: n) {
            if (!is_visited_r[i])
                explore_r(adj, i);
        }
        post_order(v);
    }

    void explore(const std::vector<std::vector<int>> &adj, const int v) {
        is_visited[v] = true;
        post_visit[v] = 0;
        std::vector<int> n = adj[v];
        for (auto &i: n) {
            if (!is_visited[i])
                explore(adj, i);
        }
    }

    void DFS(const std::vector<std::vector<int>> &adj) {
        clock = 1;
        pre_visit.resize(adj.size());
        post_visit.resize(adj.size());
        for (int i = 0; i < adj.size(); ++i) {
            if (!is_visited_r[i])
                explore_r(adj, i);
        }
    }

    int get_scc(const std::vector<std::vector<int>> &adj) {
        int scc = 0;
        is_visited.resize(adj.size());
        is_visited_r.resize(adj.size());
        for (int i = 0; i < adj.size(); ++i) {
            is_visited[i] = is_visited_r[i] = false;
        }
        std::vector<std::vector<int>> adj_r = reverse_graph(adj);
        DFS(adj_r);
        auto it = std::max_element(post_visit.begin(), post_visit.end());
        while (*it != 0) {
            auto v = it - post_visit.begin();
            if (!is_visited[v]) {
                explore(adj, v);
                scc++;
            }
            it = std::max_element(post_visit.begin(), post_visit.end());
        }
        return scc;
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
    int scc = graph::get_scc(adj);
    std::cout << scc;
    return 0;
}