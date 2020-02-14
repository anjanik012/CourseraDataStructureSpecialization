#include<iostream>
#include<vector>

using namespace std;

int maj_element_naive(vector<int> &a){
    //Brute force algorithm. O(n*n)
    int count = 0;
    int stop = a.size();
    for(auto i = a.begin(); i != a.end() ; i++){
        count = 0;
        for(auto j = a.begin(); j != a.end(); j++){
            if(*j == *i)
                count++;
            if (count > stop/2) {
            return *j;
           }
        }
    }
    return -1;
}

int count(vector<int>::iterator first, vector<int>::iterator last, int key){
    size_t cnt = 0;
    for(auto i = first; i <= last; i++){
        if(*i == key)
            cnt++;
    }
    return cnt;
}

int maj_element_fast(vector<int> &a, vector<int>::iterator left, vector<int>::iterator right){
    //A Divide and conquer algorithm. O(nlogn)
    if(left == right)
        return *left;
    if(left + 1 == right){
        if(*left == *right)
            return *left;
        else
            return -1;
    }

    auto mid = left + (right - left)/2;
    int r1 = maj_element_fast(a, left , mid);
    int r2 = maj_element_fast(a, mid + 1, right);            
    
    if(r1 == -1 && r2 == -1)
        return -1;
    if(r1 == r2)
        return r1;
    else{
        size_t c1,c2;
        if(r1 == -1){
            c1 = 0;
            c2 = count(left, mid, r2) + count(mid + 1, right, r2);
        }
        else if(r2 == -1){
            c2 = 0;
            c1 = count(left, mid, r1) + count(mid + 1, right, r1);
        }
        else{
            c1 = count(left, mid, r1) + count(mid + 1, right, r1);
            c2 = count(left, mid, r2) + count(mid + 1, right, r2);
        }
        size_t sz = right - left + 1;
        if(c1 > sz/2)
            return r1;
        else if(c2 > sz/2)
            return r2;
        else
            return -1;
    }
}

bool maj_element_wrap(vector<int> &a, vector<int>::iterator left, vector<int>::iterator right){
    return (maj_element_fast(a, left, right) > 0)?1:0;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<maj_element_wrap(a, a.begin(), a.end() - 1)<<endl;

    return 0;
    
}
