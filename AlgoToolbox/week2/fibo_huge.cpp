#include<iostream>

using namespace std;

int period(int m){
	int r = 1;
	int a =0, b = 1 , c;
	do{
		c = (a+b)%m;
		a = b;
		b = c;
		r++;
	}while(!(c==0 && a==1));
	return r;
}

uint64_t fibo_last(uint64_t n){
	if(n <= 1)
		return n;
	else{
		uint64_t a=0UL , b=1UL , c;
		uint64_t i =2UL;
		while(i <= n){
			c = a + b;
			a = b;
			b = c;
			i = i + 1UL;
		}
		return c;
	}
}

int fibo_mod(uint64_t n, int m){
	int p = period(m);
	return fibo_last(n%p)%m;
}

int main(){
	uint64_t n;
	int m;
	cin>>n>>m;
	cout<<fibo_mod(n , m)<<endl;
	return 0;
}

