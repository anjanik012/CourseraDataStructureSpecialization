#include<iostream>
#include<vector>
#include<queue>


struct packet{
    int arr;
    int span;
};

std::vector<int> get_p_times(int S, std::vector<packet> &packets){
    std::queue<packet> buffer;
    std::vector<int> p_times;
    if(!packets.empty())
        p_times.push_back(0);
    int i,j;
    size_t time_elapsed = packets[0].span;
    for(i = 1; i < packets.size(); i++){
         for(j = 1; j < S; j++){
            packet x = packets[j];
            p_times.push_back(time_elapsed);
            time_elapsed = time_elapsed + x.span;
            
         }
    }
    return p_times;
}

int main(){
    int S , n;
    std::cin>>S>>n;
    std::vector<packet> packets(n);
    for(int i = 0; i < n; i++){
        cin>>packets[i].arr>>packets[i].span;
    }
    std::vector<int> p_times = get_p_times(S, packets);
    for(auto i: p_times)
        std::cout<<i<<std::endl;
    return 0;
}