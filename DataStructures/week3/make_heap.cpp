#include<iostream>
#include<vector>
#include<utility>


namespace anjani{
    
    struct indices{
        int i;
        int j;
    };

    std::vector<indices> make_heap(std::vector<int> &range){
        std::vector<indices> pairs;
        indices pair;
        int sz = range.size();
        for(int i = (sz - 1)/2; i >= 0 ; i--){
            // std::cout<<"make_heap:"<<i<<std::endl;
            int min_i = i;
            int j = i;
            int l = 2*min_i + 1;
            int r = 2*min_i + 2;
            while(l <= sz - 1){
                if(range[l] < range[min_i])
                    min_i = l;
                if(r <= sz - 1 && range[r] < range[min_i])
                    min_i = r;
                if(j != min_i){
                    pair.i = j;
                    pair.j = min_i;
                    pairs.push_back(pair);
                    std::swap(range[j], range[min_i]);
                }
                else{
                    break;
                }
                // min _i = i;
                j = min_i;
                l = 2*min_i + 1;
                r = 2*min_i + 2;
                
            }
        }
        return pairs;
    }


};

int main(){
    int n;
    std::cin>>n;
    std::vector<int> range(n);
    for(int i = 0; i < n ; i++){
        std::cin>>range[i];
    }
    std::vector<anjani::indices> all_pairs = anjani::make_heap(range);
    std::cout<<all_pairs.size()<<std::endl;
    for(auto pair : all_pairs){
        std::cout<<pair.i<<' '<<pair.j<<std::endl;
    }
    return 0;
}