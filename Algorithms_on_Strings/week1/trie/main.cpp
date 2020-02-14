#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
    trie t(1, map<char, int>());
    int i, count = 0;
    for (const auto &pattern: patterns) {
        i = 0;
        for (const auto &c: pattern) {
//            int x = t.size() - 1;
//            if (i > x) {
//                for (int j = 0;j < (i - x); j++) {
//                    t.push_back(map<char, int>());
//                }
//            }
            auto f_r = t[i].find(c);
            if (f_r != t[i].end()) {
                i = f_r->second;
            } else {
                t[i].insert({c, count + 1});
                count++;
                i = count;
                t.push_back(map<char, int>());
            }
        }
    }
    return t;
}

int main() {
    size_t n;
    std::cin >> n;
    vector<string> patterns;
    for (size_t i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        patterns.push_back(s);
    }

    trie t = build_trie(patterns);
    for (size_t i = 0; i < t.size(); ++i) {
        for (const auto & j : t[i]) {
            std::cout << i << "->" << j.second << ":" << j.first << "\n";
        }
    }

    return 0;
}