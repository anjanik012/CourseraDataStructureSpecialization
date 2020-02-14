#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

int const Letters = 4;
int const NA = -1;

struct Node {
    int next[Letters];

    Node() {
        fill(next, next + Letters, NA);
    }

    bool isLeaf() const {
        return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
    }
};

int letterToIndex(char letter) {
    switch (letter) {
        case 'A':
            return 0;
            break;
        case 'C':
            return 1;
            break;
        case 'G':
            return 2;
            break;
        case 'T':
            return 3;
            break;
        default:
            assert (false);
            return -1;
    }
}

trie build_trie(const vector<string> & patterns) {
    trie t(1, map<char, int>());
    int i, count = 0;
    for (const auto &pattern: patterns) {
        i = 0;
        for (const auto &c: pattern) {
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

void prefix_matching(const trie &t, const string &text, const int start, vector<int> &result) {
    auto symbol = text.begin();
    int v = 0;
    while (true) {
        auto find_result = t[v].find(*symbol);
        if (t[v].empty()) {
            result.push_back(start);
            return;
        } else if (find_result != t[v].end()) {
            symbol++;
            v = find_result->second;
        } else {
            return;
        }
    }
}

vector<int> solve(string &text, int n, const vector<string> &patterns) {
    vector<int> result;
    trie t = build_trie(patterns);
    int size = text.size();
    for (int i = 0; i < size; i++) {
        prefix_matching(t, text, i, result);
        text = text.substr(1, string::npos); //Remove the first character of the string only.
    }
    return result;
}

int main() {
    string t;
    cin >> t;

    int n;
    cin >> n;

    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }

    vector<int> ans;
    ans = solve(t, n, patterns);

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i];
        if (i + 1 < (int) ans.size()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
