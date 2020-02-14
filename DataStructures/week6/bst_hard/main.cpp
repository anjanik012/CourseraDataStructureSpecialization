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

//    void in_order_left(const node *r) {
//        if (r == nullptr)
//            return;
//        in_order_left(r->left_child);
//
//        if (!is_bst)
//            return;
//
//        if (r->key > temp) {
//            temp = r->key;
//        } else {
//            is_bst = false;
//            return;
//        }
//        in_order_left(r->right_child);
//    }
//
//    void in_order_right(const node *r) {
//        if (r == nullptr)
//            return;
//        in_order_right(r->left_child);
//
//        if (!is_bst)
//            return;
//
//        if (r->left_child != nullptr){
//            if (r->key <= temp){
//                is_bst = false;
//                return;
//            }
//        }
//
//        if (r->key >= temp){
//            temp = r->key;
//        } else{
//            is_bst = false;
//            return;
//        }
//        in_order_right(r->right_child);
//    }


    int64_t in_order_left(node *r) {
        if (r->left_child == nullptr && r->right_child == nullptr)
            return r->key;
        int64_t r_max, l_min;
        r_max = in_order_left(r->left_child);
        temp = r->key;
        if (temp <= r_max) {
            is_bst = false;
            return INT64_MIN;
        }
        l_min = in_order_right(r->right_child);
        return r_max;
    }

    int64_t in_order_right(node *r) {

    }

    bool is_bst_f() {
        in_order_left(root->left_child);

        if (!is_bst)
            return false;

        if (root->key > temp)
            temp = root->key;
        else
            return false;
        in_order_right(root->right_child);
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