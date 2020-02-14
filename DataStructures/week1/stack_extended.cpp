#include<iostream>
#include<vector>
#include<string>
#include<limits>

namespace anjani{

class stack{
    private:

        struct node{
            node *ptr;
            int key;
        };

        node *top;
        node *extra;

        int top_peek(){
            return top->key;
        }
        int extra_peek(){
            return extra->key;
        }
    public:
        stack(){
            top = extra = NULL;
        }
        void push(int k){
            if(top == NULL){
                top = new node;
                extra = new node;
                top->key = extra->key = k;
                top->ptr = extra->ptr = NULL;
            }
            else{
                if(k < extra_peek()){
                    node *temp = new node;
                    temp->key = k;
                    temp->ptr = top;
                    top = temp;
                }
                else{
                    node *temp1 = new node;
                    node *temp2 = new node;
                    temp1->key = temp2->key = k;
                    temp1->ptr = top;
                    top = temp1;
                    temp2->ptr = extra;
                    extra = temp2;
                }
            }
        }
        int pop(){
            int r;
            if(top_peek() == extra_peek()){
                node *temp1 = top;
                node *temp2 = extra;
                top = top->ptr;
                extra = extra->ptr;
                r = temp1->key;
                delete temp1;
                delete temp2;
            }
            else{
                node * temp = top;
                top = top->ptr;
                r = temp->key;
                delete temp;
            }
            return r;
        }
        int max(){
            return extra->key;
        }
      
};

};

std::vector<int> get_max_queries(const std::vector<std::string> &queries){
    anjani::stack _stack;
    std::vector<int> maxes;
    for(auto query : queries){
        if(query[0] == 'p' && query[1] == 'u'){
            std::string n(query.begin() + 5, query.end());
            int k = std::stoi(n);
            _stack.push(k);
        }
        if(query == "pop"){
            _stack.pop();
        }
        if(query == "max"){
            maxes.push_back(_stack.max());
        }
    }
    return maxes;
}


int main(){
    int q;
    std::cin>>q;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<std::string> queries(q);
    for(int i = 0 ; i < q; i++){
        std::getline(std::cin, queries[i]);
    }
    
    std::vector<int> max_queries = get_max_queries(queries);
    for(auto i : max_queries)
        std::cout<<i<<std::endl;
    return 0;
}