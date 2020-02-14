#include <iostream>
#include <vector>

namespace anjani {
    class quick_union {
    private:
        int *id;
        int *sz;
        int max_size;

        int root(int i) {
            while (i != id[i]) {
                id[i] = id[id[i]];//path compression heuristic
                i = id[i];
            }
            return i;
        }

    public:
        quick_union(int n) {
            id = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; ++i) {
                id[i] = i;
                sz[i] = 1;
            }
        }

        explicit quick_union(const std::vector<int> &x) {
            int n = x.size();
            id = new int[n];
            sz = new int[n];
            max_size = -1;
            for (int i = 0; i < n; ++i) {
                id[i] = i;
                sz[i] = x[i];
                if (sz[i] > max_size)
                    max_size = sz[i];
            }
        }

        bool connected(int p, int q) {
            return root(p) == root(q);
        }

        int _union(int p, int q) {
            int i = root(p);
            int j = root(q);
            if (i != j) {
                id[j] = i;
                sz[i] += sz[j];
                if (sz[i] > max_size)
                    max_size = sz[i];
            }
            return max_size;
        }
    };

    struct pair {
        int p;
        int q;
    };

    std::vector<int> merger(const std::vector<int> &sizes, const std::vector<pair> &pairs) {
        quick_union qu(sizes);
        std::vector<int> ans(pairs.size());
        auto i = ans.begin();
        for (auto &pair: pairs) {
            *i = qu._union(pair.p - 1, pair.q - 1);
            i++;
        }
        return ans;
    }
};


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> sizes(n);
    for (int i = 0; i < n; ++i)
        std::cin >> sizes[i];

    std::vector<anjani::pair> queries(m);
    for (int i = 0; i < m; ++i)
        std::cin >> queries[i].p >> queries[i].q;

    std::vector<int> ans = anjani::merger(sizes, queries);

    for (auto i : ans)
        std::cout << i << std::endl;

    return 0;
}