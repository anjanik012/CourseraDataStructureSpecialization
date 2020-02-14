#include<iostream>

using namespace std;

int fibo_last(int64_t n){
	int x = n % 60;
	if(x <= 1)
		return x;
	else{
		int a , b , c;
		a = 0; b = 1;
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

int fibo_sum_last(int64_t n){
	int r = fibo_last(n+2);
	if(r == 0)
		return 9;
	else
		return r-1;
	
}

int fibo_ps_last(int64_t m , int64_t n){
	if(m == n)
		return fibo_last(n);

	int fm = fibo_sum_last(m - 1);
	int fn = fibo_sum_last(n);

	if(fn >= fm)
		return fn - fm;
	else
		return 10 + fn - fm;

}

int main(){
	int64_t m,n;
	cin>>m>>n;

	cout<<fibo_ps_last(m,n)<<endl;
	return 0;
}


