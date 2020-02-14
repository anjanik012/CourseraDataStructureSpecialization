#include<iostream>
#include<vector>

using namespace std;

uint64_t MaxPairPro(const vector<uint64_t> &A){
	int l, sl;
	l = 0;
	for(int i = 1 ; i < A.size(); i++){
		if(A[i] > A[l])
			l = i;
	}
	if(l == 0)
		sl = 1;
	else
		sl = 0;
	for(int i = 0 ; i < A.size(); i++){
		if( i!=l && A[i] > A[sl])
			sl = i;
	}
	return A[l] * A[sl];
}


int main(){
	int n;
	cin>>n;
	vector<uint64_t> v(n);
	for(int i = 0 ; i < n ; i++)
		cin>>v[i];
	cout<<MaxPairPro(v)<<endl;
	return 0;
}
