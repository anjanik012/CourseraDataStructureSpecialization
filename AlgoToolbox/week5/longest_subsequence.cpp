#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int long_sub(vector<int> &a, vector<int> &b){
    int **T = new int*[a.size() + 1];
    for (size_t i = 0; i < a.size() + 1; i++){
        T[i] = new int[b.size() + 1];
    }
    
    for (size_t i = 0; i < a.size() + 1; i++){
        T[i][0] = 0;
    }
    for (size_t i = 0; i < b.size() + 1; i++){
        T[0][i] = 0;
    }
    size_t i, j;

    for(j = 1; j <= b.size(); j++){
        for(i = 1; i <= a.size(); i++){
            int temp;
            if(a[i-1] == b[j-1]){
                temp = max({T[i][j-1], T[i-1][j], T[i-1][j-1] + 1});
            }
            else{
                temp = max({T[i][j-1], T[i-1][j], T[i-1][j-1]});
            }
            T[i][j] = temp;
        }
    }
    return T[i-1][j-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        cin>>b[i];
    }

    int ls = long_sub(a,b);
    cout<<ls<<endl;
    return 0;
}

