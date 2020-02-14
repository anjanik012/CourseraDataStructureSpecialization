#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int64_t max_val(vector<int> num, vector<char> op){
    int n = num.size();
    int64_t M[n][n], m[n][n];
    for(int i = 0; i < n ; i++)
        M[i][i] = m[i][i] = num[i];
    
    int i,j,k,s;
     int64_t minimum = INT64_MAX;
     int64_t maximum = INT64_MIN;
    for(s = 1; s <= n - 1; s++){
        for(i = 0; i < n - s; i++){
            j = i + s;
            minimum = INT64_MAX;
            maximum = INT64_MIN;
            for(k = i; k < j ; k++){
                int64_t a,b,c,d;    
                switch (op[k]) {
                case '+':
                    a = M[i][k] + M[k+1][j];
                    b = M[i][k] + m[k+1][j];
                    c = m[i][k] + M[k+1][j];
                    d = m[i][k] + m[k+1][j];
                    minimum = min({minimum, a, b, c, d});
                    maximum = max({maximum, a, b, c, d});
                    break;
                case '-':
                    a = M[i][k] - M[k+1][j];
                    b = M[i][k] - m[k+1][j];
                    c = m[i][k] - M[k+1][j];
                    d = m[i][k] - m[k+1][j];
                    minimum = min({minimum, a, b, c, d});
                    maximum = max({maximum, a, b, c, d});
                    break;
                case '*':
                    a = M[i][k] * M[k+1][j];
                    b = M[i][k] * m[k+1][j];
                    c = m[i][k] * M[k+1][j];
                    d = m[i][k] * m[k+1][j];
                    minimum = min({minimum, a, b, c, d});
                    maximum = max({maximum, a, b, c, d});
                    break;
                }
            }
            m[i][j] = minimum;
            M[i][j] = maximum;
        }
    }
    return M[0][n-1];
}


int main(){
    string a;
    getline(cin, a);
    vector<int> numbers;
    vector<char> op;
    for(int i = 0; i < a.length(); i++){
        if(i % 2 == 0){
            numbers.push_back(a[i] - 48);
        }
        else{
            op.push_back(a[i]);
        }
    }
    int64_t res = max_val(numbers, op);
    cout<<res<<endl;

    return 0;
}