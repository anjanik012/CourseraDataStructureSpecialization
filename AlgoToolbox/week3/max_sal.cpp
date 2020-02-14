#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool is_greater_or_equal(string digit, string max_digit){
	char af = digit.at(0);
	char bf = max_digit.at(0);

	if(af == bf && digit.length() > max_digit.length())
		return false;

	if(af >= bf)
		return true;
	else
		return false;
}

string max_sal(vector<string> digits){
	string answer = "";
	while(!digits.empty()){
	string max_digit = "0";
	auto it = digits.begin();
	vector<string>::iterator remove;
	while(it != digits.end()){
		if(is_greater_or_equal(*it, max_digit)){
			max_digit = *it;
			remove = it;
		}
		it++;
	}
	answer = answer + max_digit;
	digits.erase(remove);
	}
	return answer;
}


int main(){

	int n;
	cin>>n;

	vector<string> digits(n);
	for(int i = 0 ; i < n; i++)
		cin>>digits[i];
	string ans = max_sal(digits);
	cout<<ans<<endl;

	return 0;
}

