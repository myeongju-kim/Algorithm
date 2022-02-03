#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
int Priority(char ch) {
	switch (ch) {
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '(':
	case ')':
		return 3;
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		// 대문자
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		//  +, -, *, /
		else {
			if (str[i] == ')') {
				char ch = st.top();
				st.pop();
				while (ch != '(') {
					cout << ch;
					ch = st.top();
					st.pop();
				}
			}
			else {
				int b = Priority(str[i]);
				while (!st.empty()) {
					char ch = st.top();
					if (ch == '(')break;
					int a = Priority(ch);
					if (a >= b) {
						st.pop();
						cout << ch;
					}
					else break;
				}
				st.push(str[i]);
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}