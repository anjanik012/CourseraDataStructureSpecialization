#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

struct range{
    int low;
    int high;
};

bool binary_search(vector<int>::iterator first, vector<int>::iterator last, int key){
    if(first > last)
        return false;
    vector<int>::iterator mid = first + (last - first)/2;
    if(key == *mid)
        return true;
    else if(key < *mid)
        return binary_search(first, mid - 1, key);
    else
        return binary_search(mid + 1, last, key);
}

vector<int> num_segments(vector<range> &segments, vector<int64_t> &points){
    vector<int> res(points.size(), 0), temp;
    
    for(auto segment : segments){
        temp.resize(segment.high - segment.low + 1);
        iota(temp.begin(), temp.end(), segment.low);
        
        for(size_t i = 0; i < points.size(); i++){
            if(binary_search(temp.begin(), temp.end() - 1, points[i])){
                res[i]++;
            }
        }
    }
    return res;
}

vector<int> num_segments_fast(vector<range> &segments, vector<int64_t> &points){
    vector<int> res(points.size(), 0);

    for(auto segment : segments){
        for(size_t i = 0; i < points.size(); i++){
            if(points[i] >= segment.low && points[i]<= segment.high)
                res[i]++;
        }
    }
    
    return res;
}


int main(){
    int s,p;
    cin>>s>>p;
    vector<range> ranges(s);
    vector<int64_t> points(p);

    for (size_t i = 0; i < s;i++){
        cin>>ranges[i].low>>ranges[i].high;
    }

    for (size_t i = 0; i < p; i++){
        cin>>points[i];
    }
    
    vector<int> result = num_segments_fast(ranges, points);
    for (size_t i = 0; i < p; i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;
    return 0;
}
