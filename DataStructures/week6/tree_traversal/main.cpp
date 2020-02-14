#include <iostream>
#include <vector>

// All are depth first traversal methods
//in-order, pre-order, post-order

struct node_val {
    int key;
    int left_child;
    int right_child;
};

class binary_tree {
private:
    struct node {
        int key;
        node *left_child;
        node *right_child;
    };
    node *nodes;
    node *root;
public:
    explicit binary_tree(const int n, const std::vector<node_val> &values) {
        nodes = new node[n];
        for (int i = 0; i < n; ++i) {
            nodes[i].key = values[i].key;
            if (i == 0)
                root = &nodes[i];

            if (values[i].left_child >= 0)
                nodes[i].left_child = &nodes[values[i].left_child];
            else
                nodes[i].left_child = nullptr;
            if (values[i].right_child >= 0)
                nodes[i].right_child = &nodes[values[i].right_child];
            else
                nodes[i].right_child = nullptr;
        }
    }

    node *get_root() {
        return root;
    }

    static void in_order_seq(node *root) {
        if (root == nullptr)
            return;
        in_order_seq(root->left_child);
        std::cout << root->key << ' ';
        in_order_seq(root->right_child);
    }

    static void pre_order_seq(node *root) {
        if (root == nullptr)
            return;
        std::cout << root->key << ' ';
        pre_order_seq(root->left_child);
        pre_order_seq(root->right_child);
    }

    static void post_order_seq(node *root) {
        if (root == nullptr)
            return;
        post_order_seq(root->left_child);
        post_order_seq(root->right_child);
        std::cout << root->key << ' ';
    }

};

int main() {
    int n;
    std::cin >> n;
    std::vector<node_val> val(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> val[i].key >> val[i].left_child >> val[i].right_child;
    }
    binary_tree bt(n, val);
    binary_tree::in_order_seq(bt.get_root());
    std::cout << std::endl;
    binary_tree::pre_order_seq(bt.get_root());
    std::cout << std::endl;
    binary_tree::post_order_seq(bt.get_root());
    return 0;
}


