#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search(vector<int> &a, vector<int>::iterator left, vector<int>::iterator right, int key){
    if(left > right)
        return -1;
        
    vector<int>::iterator mid = left + (right - left)/2;
    
    if(key == *mid)
        return mid - a.begin();
    if(key < *mid)
        return binary_search(a, left, mid - 1, key);
    else
        return binary_search(a, mid + 1, right, key);   
}

int linear_search(vector<int> &a, vector<int>::iterator first, vector<int>::iterator last, int key){
    for(auto i = first; i <= last; i++){
        if(*i == key)
            return i - a.begin();
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
        cin>>a[i];

    int m;
    cin>>m;
    vector<int> b(m);

    for (size_t i = 0; i < m; i++) 
        cin>>b[i];         

    for (size_t i = 0; i < m; i++)
        cout<<binary_search(a, a.begin(), a.end() - 1, b[i])<<' ';
    
    cout<<endl;       
    
    // int n = 1;
    // vector<int> a(n);
    // while (true){
    //     int i = rand() % 100;
    //     for(int j = i, k = 0;j < i + n; j++, k++)
    //         a[k] = j;
    //     int key = a[rand() % n];
    //     int l = linear_search(a, a.begin(), a.end() - 1, key);
    //     int b = binary_search(a, a.begin(), a.end() - 1, key);
    //     if(l == b)
    //         cout<<"OK\n";
    //     else
    //         break;
    // }
    // for(int i = 0; i < n; i++)
    //     cout<<a[i]<<' ';
    // cout<<endl;
    return 0;
}

