#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct segment{
	int start;
	int end;
};

vector<int> optimal_points(vector<segment> segments){
	vector<int> ends,points;
	while(!segments.empty()){
	for(auto i : segments)
		ends.push_back(i.end);
	vector<segment>::iterator i = segments.begin();
	auto min = min_element(ends.begin(), ends.end());
	while(i != segments.end()){
		segment t = *i;
		if(*min >= t.start && *min <= t.end)
			segments.erase(i);
		else
			i++;
	}
	points.push_back(*min);
	ends.clear();
	}
	return points;
}

int main(){
	int n;
	cin>>n;
	vector<segment> segments(n);
	for(int i = 0; i < n ; i++)
		cin>>segments[i].start>>segments[i].end;

	vector<int> points = optimal_points(segments);
	cout<<points.size()<<endl;
	for(auto i : points)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}

