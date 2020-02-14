#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

long long max_ad_rev(vector<int> a , vector<int> b){
	sort(a.begin(), a.end() , greater<int>());
	sort(b.begin(), b.end() , greater<int>());

	long long max_rev = 0;
	int n = a.size();

	for(int i = 0; i < n ; i++)
		max_rev += a[i]*b[i];

	return max_rev;
}

long long max_ad_rev_g(vector<int> a , vector<int> b){
	int n = a.size();
	long long max_rev = 0;
	for(int i = 0; i < n ; i++){
		auto ia = max_element(a.begin(), a.end());
		auto ib = max_element(b.begin(), b.end());
		max_rev += *ia * *ib;
		*ia = -1000000;
		*ib = -1000000;
	}
	return max_rev;
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n ; i++)
		cin>>a[i];
	for(int i = 0; i < n ; i++)
		cin>>b[i];
	long long res = max_ad_rev(a , b);
	
	cout<<fixed<<res;	
	
/*
	while(n <= 1000){
		//if(n == 267)
		//	break;
		int x = 0;
		while(x < 500){
		cout<<"n="<<n<<" x="<<x+1<<endl;
		for(int i = 0; i < n ; i++)
			a[i] = -100000 + rand() % (2000001);
		for(int i = 0; i < n ; i++)
			b[i] = -100000 + rand() % (2000001);
		int64_t res_g = max_ad_rev_g(a , b);
		int64_t res_f = max_ad_rev( a , b);
		if(res_g == res_f)
			cout<<"OK\n";
		else
			break;
		x++;
		}
		n++;
		a.resize(n);
		b.resize(n);
	}
	for(int i = 0 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i = 0 ; i < n ; i++)
		cout<<b[i]<< " ";
*/
	return 0;
}

