#include<iostream>
#include<vector>

using namespace std;

vector<int> optimal_parts(int n){
	vector<int> parts;
	int current_choice = 1;
	while(n > 0){
		int new_choice = n - current_choice;
		if(new_choice > current_choice){
			n = n - current_choice;
			parts.push_back(current_choice);
			current_choice++;
		}
		else{
			parts.push_back(n);
			n = 0;
		}
	}
	return parts;
}


int main(){
	int n;
	cin>>n;

	vector<int> parts = optimal_parts(n);
	cout<<parts.size()<<endl;
	for(auto i : parts)
		cout<<i<<" ";

	cout<<endl;
	return 0;	
}

