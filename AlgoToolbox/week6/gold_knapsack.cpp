#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int optimal_gold(int W, vector<int> &weights){
    int n = weights.size();
    int **V = new int*[W + 1];
    for(int i = 0; i < W + 1; i++)
        V[i] = new int[n + 1];

    for(int i = 0; i < W + 1; i++)
        V[i][0] = 0;
    for(int i = 0; i < n + 1; i++)
        V[0][i] = 0;
    int i,w,val;
    for(i = 1 ; i <= n; i++){
        for(w = 1; w <= W; w++){
            V[w][i] = V[w][i-1];
            if(weights[i - 1] <= w){
                val = V[w-weights[i - 1]][i-1] + weights[i - 1];
                if(val > V[w][i])
                    V[w][i] = val;
            }
        }
    }
    return V[w-1][i-1];
}

int main(){
    int W,n;
    cin>>W>>n;
    vector<int> weights(n);
    for(int i = 0 ; i < n; i++)
        cin>>weights[i];
    
    int max_w = optimal_gold(W, weights);
    cout<<max_w<<endl;
    return 0;
}

