#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int64_t key;
    int64_t left;
    int64_t right;

    Node() : key(0), left(-1), right(-1) {}
    Node(int64_t key_, int64_t  left_, int64_t right_) : key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

void in_order_t(vector<int64_t > &result, int64_t root) {
    if (root == -1) return;
    in_order_t(result, tree[root].left);
    result.push_back(root);
    in_order_t(result, tree[root].right);
}

vector <int64_t > in_order(const vector<Node>& tree) {
    vector<int64_t > result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    in_order_t(result, 0L);

    return result;
}


bool is_bst(const vector<Node>& tree) {
    // Implement correct algorithm here
    if (tree.size() > 1) {
        vector <int64_t > v = in_order(tree);

        for (int64_t i = 0; i < v.size() - 1; i++) {
            if (tree[v[i + 1]].key < tree[v[i]].key) return false;
            if (tree[v[i]].key == tree[v[i + 1]].key && tree[v[i + 1]].left == v[i]) return false;
        }
    }
    return true;
}

int main() {
    int64_t nodes;
    cin >> nodes;

    for (int64_t i = 0; i < nodes; ++i) {
        int64_t key, left, right;
        cin >> key >> left >> right;
        tree.emplace_back(Node(key, left, right));
    }
    if (is_bst(tree)) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
