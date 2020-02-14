#include<iostream>
using namespace std;

uint64_t Fibo(int n){
	if(n <= 1)
		return n;
	else
		return Fibo(n-1) + Fibo(n-2);
}

uint64_t FiboFast(int n){
	uint64_t a , b , c;
	a = 0; b = 1;
	if (n <= 1)
		return n;
	else if(n == 2)
		return b;
	else{
		int i = 2;
		while(i <= n){
			c = a + b;
			a = b;
			b = c;
			i++;
		}
		return c;
	}
}

int main(){
	/*uint64_t r1, r2;
	for(int i = 0 ; i <= 45 ; i++){
		r1 = Fibo(i);
		r2 = FiboFast(i);
		if(r1!=r2){
			cout<<"r1="<<r1<<" r2="<<r2<<" i="<<i<<endl;
			break;
		}
		else
			cout<<"OK"<<endl;
	}
	*/
	int n;
	cin>>n;
	cout<<FiboFast(n) << endl;
	return 0;
}
