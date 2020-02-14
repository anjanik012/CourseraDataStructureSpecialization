#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

class node{
    private:
        int key;
        std::vector<node*> children;
    public:
        void add_child(node *child){
            children.push_back(child);
        }
        void set_key(int k){
            key = k;
        }
        std::vector<node*> get_children(){
            return children;
        }
        int get_key(){
            return key;
        }
};

class tree{
    private:
        node *root;
        node *nodes;
    public:
        tree(std::vector<int> &tree_des){
            nodes = new node[tree_des.size()];
            // for(size_t i = 0; i < tree_des.size(); i++){
            //     nodes[i].set_key(i);
            //     for(size_t j = 0; j < tree_des.size(); j++){
            //         if(i == tree_des[j]){
            //             nodes[i].add_child(&nodes[j]);
            //         }
            //     }
            //     if(tree_des[i] == -1)
            //         root = &nodes[i];
            // }
            for(size_t i = 0; i < tree_des.size(); i++){
                if(tree_des[i] == -1){
                    root = &nodes[i];
                    continue;
                }
                nodes[tree_des[i]].add_child(&nodes[i]);
            }
        }
        node *get_root(){
            return root;
        }
        static uint64_t tree_height(node *r){
            //Recursive
            std::vector<node*> children = r->get_children();
            if(children.empty()){
                return 1;
            }
            std::vector<uint64_t> heights(children.size());
            size_t k = 0;
            for(auto i : children){
                heights[k++] = tree_height(i);
            }
            return *std::max_element(std::begin(heights), std::end(heights)) + 1;
        }

        static uint64_t tree_height_fast(node *r){
            //Iterative
            node *temp;
            std::queue<node*> levels;
            std::vector<node*> children;
            uint64_t level = 0, nl = 1, nl1 = 0;
            levels.push(r);
            while(!levels.empty()){
                temp = levels.front();
                children = temp->get_children();
                nl1 = nl1 + children.size();
                nl--;
                if(nl == 0){
                    level++;
                    nl = nl1;
                    nl1 = 0;
                }
                for(auto child : children){
                    levels.push(child);
                }
                levels.pop();
            }            
            return level;
        }
};


int main(){
    int n;
    std::cin>>n;
    std::vector<int> nodes(n);
    for(size_t i = 0; i < n; i++)
        std::cin>>nodes[i];
    tree t(nodes);
    uint64_t h = tree::tree_height_fast(t.get_root());
    std::cout<<h<<std::endl;

    return 0;
}