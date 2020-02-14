#include<iostream>

using namespace std;

int change(int m){
	int r = 0;
	while(m > 0){
		if(m >= 10)
			m = m - 10;
		else if(m >= 5)
			m = m - 5;
		else
			m = m - 1;
		r++;
	}
	return r;
}

int main(){
	int m;
	cin>>m;
	cout<<change(m)<<endl;
	return 0;
}


