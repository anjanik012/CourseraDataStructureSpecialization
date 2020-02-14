#include<iostream>

using namespace std;

int fibo_last(uint64_t x){
	int n = x % 60;

	if(n <= 1)
		return n;
	else{
		int a , b , c;
		a = 0;b = 1;
		uint64_t i = 2;
		while(i <= n){
			c = (a%10) + (b%10);
			c%=10;
			a = b;
			b = c;
			i++;
		}
		return c;
	}
}

int fibo_sum_last(uint64_t n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else{
		int r = fibo_last(n+2);
		if(r == 0)
			return 9;
		else
			return r - 1;
	}
		
}

int main(){
	uint64_t n;
	cin>>n;
	cout<<fibo_sum_last(n)<<endl;
	return 0;
}
