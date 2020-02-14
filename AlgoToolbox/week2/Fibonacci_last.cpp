#include<iostream>

using namespace std;

int fibo_last(long n){
	if(n <= 1)
		return n;
	else{
		int i = 2;
		int a , b , c;
		a = 0;b = 1;
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

int main(){
	long n;
	cin>>n;
	cout<<fibo_last(n);
	return 0;
}
