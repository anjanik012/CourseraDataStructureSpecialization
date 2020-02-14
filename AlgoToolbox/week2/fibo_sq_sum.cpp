#include<iostream>

using namespace std;

int fibo_last(uint64_t n){
	int x = n % 60;
	if(x <= 1)
		return x;
	else{
		int a , b ,c;
		a = 0 ; b = 1;
		int i = 2;
		while(i <= x){
			c = (a%10) + (b%10);
			c%=10;
			a = b;
			b = c;
			i++;
		}
		return c;
	}
}


int fibo_sq_sum(uint64_t n){
	int r = fibo_last(n) * fibo_last(n+1);
	return r%10;
}


int main(){
	uint64_t n;
	cin>>n;
	cout<<fibo_sq_sum(n)<<endl;
	return 0;
}

