#include<iostream>

using namespace std;

uint64_t GCD(uint64_t a, uint64_t b){
	if(b == 0)
		return a;
	else
		return GCD(b , a%b);
}

int main(){
	uint64_t a,b;
	cin>>a>>b;
	cout<<GCD(a,b)<<endl;
	return 0;
}
