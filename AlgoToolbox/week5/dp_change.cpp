#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int dp_change(int money, const vector<int> &coins){
    vector<int> min_num_coins(money + 1);
    min_num_coins[0] = 0;
    for(int m = 1; m <= money; m++){
        min_num_coins[m] = INT32_MAX;
        for(auto i : coins){
            if(m >= i){
                int num_coins = min_num_coins[m - i] + 1;
                if(num_coins < min_num_coins[m])
                    min_num_coins[m] = num_coins;
            }
        }
    }
    return min_num_coins[money];
}

int main(){
    int n;
    cin>>n;
    vector<int> coins = {1, 3, 4};
    int min_coins = dp_change(n, coins);
    cout<<min_coins<<endl;
    return 0;
}
