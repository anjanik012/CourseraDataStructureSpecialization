#include<iostream>

using namespace std;

uint64_t gcd(uint64_t a , uint64_t b){
	if( b == 0)
		return a;
	else
		return gcd(b , a%b);
}

uint64_t lcm(uint64_t a , uint64_t b){
	uint64_t g = gcd(a , b);
	return ((a*b)/g)/gcd(a/g , b/g);
}

int main(){
	uint64_t a , b;
	cin>>a>>b;
	cout<<lcm(a,b)<<endl;
	return 0;
}

