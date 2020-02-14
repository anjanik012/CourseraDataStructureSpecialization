#include<iostream>
#include<vector>

using namespace std;

uint64_t num_inv_naive(vector<int> &a){
    //Naive Algorithm using Brute Force. O(n*n)
    uint64_t count = 0;
    for(auto i = a.begin(); i != a.end() - 1; i++){
        for(auto j = i + 1; j != a.end(); j++){
            if(*i > *j)
                count++;
        }
    }
    return count;
}

uint64_t merge_count(vector<int> &a, vector<int>::iterator left, vector<int>::iterator right){
    //Helper Function for num_inv.
    uint64_t count = 0;
    vector<int>::iterator mid = left + (right - left)/2;
    vector<int> v;
    vector<int>::iterator b = left, c = mid + 1;

    while(b <= mid && c <= right){
        if(*b <= *c){
            v.push_back(*b);
            b++;
        }
        else{
            v.push_back(*c);
            count += mid - b + 1;
            c++;
        }
    }
    while(b <= mid){
        v.push_back(*b);
        b++;
    }
    while(c <= right){
        v.push_back(*c);
        c++;
    }
    for(auto i = left, j = v.begin(); i <= right; i++,j++){
        *i = *j;
    }
    return count;
}

uint64_t num_inv_fast(vector<int> &a, vector<int>::iterator left, vector<int>::iterator right){
    //A Divide and conquer algorithm.Much Faster... O(nlogn)    
    uint64_t count = 0;
    if(left == right)
        return count;
    vector<int>::iterator mid = left + (right - left)/2;
    count += num_inv_fast(a, left, mid);
    count += num_inv_fast(a, mid + 1, right);
    count += merge_count(a, left , right);
    return count;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<num_inv_fast(a, a.begin(), a.end() - 1)<<endl;
    // int n = 8;
    // vector<int> a(n);
    // while(true){
    //     for(int i = 0; i < n; i++)
    //         a[i] = rand() % 1000000000 + 1;
    //     if(num_inv_naive(a) == num_inv_fast(a, a.begin(), a.end() -1))
    //         cout<<"OK\n";
    //     else
    //         break;    
    // }
    // for(int i = 0; i < n; i++)
    //     cout<<a[i]<<' ';
    return 0;
}

