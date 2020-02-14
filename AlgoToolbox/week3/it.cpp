#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v = {5,4,3,2,1,0};
	
	vector<int>::iterator i = v.begin();
	i++;
	v.erase(i);
	cout<< *i  <<endl;

	return 0;
}
