#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

double max_loot(int C , vector<int> v, vector<int> w){
	vector<double> vi;
	double frac = 0.0;
	for(int i = 0; i < v.size(); i++)
		vi.push_back((double)v[i]/w[i]);
	
	vector<double>::iterator it;
	while(C > 0 &&  *(it = max_element(vi.begin(), vi.end())) > 0){
		int i = it - vi.begin();
		if(C - w[i] >= 0)
			frac = frac + v[i];
		else
			frac = frac + v[i] * ((double)C/w[i]);
		
		C = C - w[i];
		vi[i] = -1;
	}
	return frac;
}

int main(){
	/*THIS COMMENTED FRFAGMENT IS A STRESS TEST TO FIND INPUT WHICH GENERATED 
	NEGATIVE ANSWER.
	int n = 1;
	int capacity = 100;
	vector<int> values(n);
	vector<int> weights(n);
	double res;
	while(true){
		for(int i = 0; i < n ; i++){
			values[i] = rand()%200;
			weights[i] = rand()%70 + 1;
		}
		res = max_loot(capacity, values, weights);
		if(res < 0)
			break;
		else
			cout<<"OK\n";
	}
	cout.precision(10);
	cout<<res<<endl;
	for(int i = 0; i < n ; i++){
		cout<<values[i]<<" "<<weights[i]<<endl;
	}*/

	int n , capacity;
	cin>>n>>capacity;
	vector<int> values(n);
	vector<int> weights(n);

	for(int i = 0; i < n; i++)
		cin>>values[i]>>weights[i];
	double res = max_loot(capacity, values, weights);
	cout.precision(10);
	cout<<res<<endl;

	return 0;;
}

