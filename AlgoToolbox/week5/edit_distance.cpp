#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int edit_distance(string a, string b){
    int **mat = new int*[a.length() + 1];
    for (size_t i = 0; i < a.length() + 1; i++){
        mat[i] = new int[b.length() + 1];
    }
    for (size_t i = 0; i < a.length() + 1; i++){
        mat[i][0] = i;
    }
    for (size_t i = 0; i < b.length() + 1; i++){
        mat[0][i] = i;
    }
    size_t i,j;
    for (j = 1; j <= b.length(); j++){
        for (i = 1; i <= a.length(); i++){
            if(a[i-1] == b[j-1]){
                mat[i][j] = min({mat[i][j-1] + 1, mat[i-1][j] + 1, mat[i-1][j-1]});
            }
            else{
                mat[i][j] = min({mat[i][j-1] + 1, mat[i-1][j] + 1, mat[i-1][j-1] + 1});
            }
        }
    }
    return mat[i-1][j-1];
}


int main(){
    string a,b;
    getline(cin, a);
    getline(cin, b);

    int ed = edit_distance(a, b);
    cout<<ed<<endl;
    return 0;
}