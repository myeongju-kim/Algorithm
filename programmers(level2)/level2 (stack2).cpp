#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') st.push(s[i]);
        else{
            if(st.empty()) return 0;
            while(!st.empty()){
                char ch=st.top();
                st.pop();
                if(ch=='(')break;
            }
        }

    }
    if(st.empty()) return 1;
    else return 0;
}