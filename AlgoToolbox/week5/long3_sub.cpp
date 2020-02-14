#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int long_sub3(vector<int> &a, vector<int> &b, vector<int> &c){
    int ***T = new int**[a.size() + 1];
    for(int i = 0; i < a.size() + 1; i++){
        T[i] = new int*[b.size() + 1];
        for(int j = 0; j < b.size() + 1; j++){
            T[i][j] = new int[c.size() + 1];
        }
    }

    int i,j,k;
    for(i = 0; i < b.size() + 1; i++){
        for(j = 0; j < c.size() + 1 ; j++){
            T[0][i][j] = 0;
        }
    }
    for(i = 0; i < a.size() + 1; i++){
        for(j = 0; j < c.size() + 1 ; j++){
            T[i][0][j] = 0;
        }
    }
    for(i = 0; i < a.size() + 1; i++){
        for(j = 0; j < b.size() + 1 ; j++){
            T[i][j][0] = 0;
        }
    }

    for(i = 1; i <=a.size(); i++){
        for(j = 1; j <=b.size(); j++){
            for(k = 1; k <= c.size(); k++){
                int temp;
                if(a[i-1] == b[j-1] && c[k-1] == b[j-1]){
                    temp = max({T[i][j][k-1],T[i][j-1][k],T[i][j-1][k-1],T[i-1][j-1][k-1] + 1});
                }
                else{
                    temp = max({T[i][j][k-1],T[i][j-1][k],T[i][j-1][k-1],T[i-1][j-1][k-1]});
                }
                T[i][j][k] = temp;
            }
        }
    }
    return T[i-1][j-1][k-1];
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

    int o;
    cin>>o;
    vector<int> c(o);
    for (size_t i = 0; i < o; i++)
    {
        cin>>b[i];
    }

    int ls = long_sub3(a,b,c);
    cout<<ls<<endl;
    return 0;
}

