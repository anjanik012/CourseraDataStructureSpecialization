#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_op(int n){
  int *T = new int[n + 1];
  T[0] = T[1] = 0;
  T[2] = T[3]= 1;
  for(int i = 4; i <= n; i++){
    if(i % 3 == 0){
      T[i] = min(T[i/3] + 1 , T[i-1] + 1);
    }
    else if(i % 2 == 0){
      T[i] = min(T[i/2] + 1, T[i-1] + 1);
    }
    else{
      T[i] = T[i-1] + 1;
    }
  }
  int i = n;
  vector<int> op_seq;
  while(i >= 1){
    if(T[i-1] < T[i]){
      op_seq.push_back(i);
      i--;
    }
    else if(i % 3 == 0){
      op_seq.push_back(i);
      i/=3;
    }
    else if(i % 2 == 0){
      op_seq.push_back(i);
      i/=2;
    }
    else{
      op_seq.push_back(1);
      i = 0;
    }
  }
  reverse(op_seq.begin(), op_seq.end());
  return op_seq;
}

int main() {
  int n;
  cin>>n;
  vector<int> op = optimal_op(n);
  cout<<op.size() - 1<<endl;
  for(auto i : op){
    cout<< i <<' ';
  }
  cout<<endl;
  return 0;
}
