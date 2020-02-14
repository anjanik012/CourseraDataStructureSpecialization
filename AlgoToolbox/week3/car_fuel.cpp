#include<iostream>
#include<vector>

using namespace std;

int min_refills(int m , vector<int> stops){
	int dist = 0;
	int lstop = -1;
	int refills = 0;
	vector<int>::iterator i;
	for(i = begin(stops) ; i!= end(stops) ; i++){
		if(lstop == dist){
			refills = -1;
			break;
		}
		
		if(*i - dist > m){
			lstop = dist;
			dist = *(i-1);
			refills++;
			i--;
		}
	}
	return refills;
}

int main(){
	int d, m, n;
	cin>>d>>m>>n;
	vector<int> stops(n);
	for(int i = 0 ; i < n ; i++)
		cin>>stops[i];
	stops.push_back(d);
	cout<<min_refills(m, stops)<<endl;
	return 0;
}


