#include<iostream>
#include<string>
#include<stack>

using namespace std;

int is_balanced(const string &S){
    stack<char> box;
    int i;
    int unmatched_op;
    for(i = 0; i < S.length(); i++){
        switch(S[i]){
            case '(':
            case '{':
            case '[':
                if(box.empty())
                    unmatched_op = i + 1;
                box.push(S[i]);
                break;
            case ']':
            if(!box.empty()){
                if(box.top() == '[')
                    box.pop();
                else
                    return i + 1;
            }
            else{
                return i + 1;
            }
                break;
            case '}':
            if(!box.empty()){
                if(box.top() == '{')
                    box.pop();
                else
                    return i + 1;
            }
            else{
                return i + 1;
            }
                break;
            case ')':
            if(!box.empty()){
                if(box.top() == '(')
                    box.pop();
                else
                    return i + 1;
            }
            else{
                return i + 1;
            }
                break;
        }
    }
    if(box.empty())
        return 0;
    else
        return unmatched_op;
}

int main(){
    string S;
    getline(cin, S);
    
    int res = is_balanced(S);
    if(res == 0)
        cout<<"Success"<<endl;
    else
        cout<<res<<endl;

    return 0;
}