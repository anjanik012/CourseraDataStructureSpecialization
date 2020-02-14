#include <iostream>
#include <vector>

struct node_val {
    int64_t key;
    int left_child;
    int right_child;
};

class binary_tree {
private:
    struct node {
        int64_t key;
        node *left_child;
        node *right_child;
    };
    node *nodes;
    node *root;
//    std::vector<int64_t> l_tree, r_tree;
    int64_t temp;
    bool is_bst = true;
public:
    binary_tree(const int &n, const std::vector<node_val> &values) {
        nodes = new node[n];
        root = &nodes[0];
        temp = INT64_MIN;
        const int k = values[0].key;
        for (int i = 0; i < n; ++i) {
            nodes[i].key = values[i].key;
//            if (k < values[i].key)
//                r_tree.push_back(values[i].key);
//            else if (k > values[i].key)
//                l_tree.push_back(values[i].key);

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

//    node *get_root() {
//        return root;
//    }

//    static bool find(const int64_t &key, const node *r) {
//        if (r == nullptr)
//            return false;
//        if (key == r->key)
//            return true;
//        if (key < r->key)
//            return find(key, r->left_child);
//        if (key > r->key)
//            return find(key, r->right_child);
//    }



//    bool is_bst() {
//        bool ans = true;
//        for (auto &i:l_tree) {
//            if (!find(i, root)) {
//                ans = false;
//                break;
//            }
//        }
//        if (!ans)
//            return ans;
//        for (auto &i : r_tree) {
//            if (!find(i, root)) {
//                ans = false;
//                break;
//            }
//        }
//        return ans;
//    }

    void in_order_m(const node *r){
        if (r == nullptr)
            return;
        bool ans;
        in_order_m(r->left_child);
        if (r->key < temp) {
            is_bst = false;
            return;
        }
        else{
            temp = r->key;
        }
        in_order_m(r->right_child);
    }

    bool is_bst_f() {
//        l_max(root->left_child);
//        if (l_ma > root->key) {
//            return false;
//        }
//        r_min(root->right_child);
//        return root->key < r_mi;
        in_order_m(root);
        return is_bst;
    }

};


int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << "CORRECT";
        return 0;
    }
    std::vector<node_val> val(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> val[i].key >> val[i].left_child >> val[i].right_child;
    }

    binary_tree tree(n, val);
    if (tree.is_bst_f())
        std::cout << "CORRECT";
    else
        std::cout << "INCORRECT";

    return 0;
}