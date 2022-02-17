#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main() {
	string s; cin >> s;
	stack<string> st;
	string temp;
	int flag = s.find('-');
	int sum = 0;
	if (flag != -1) {
		for (int i = flag+1; i < s.size(); i++)
			if (s[i] == '+') s[i] = '-';
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			st.push(temp);
			st.push("+");
			temp = "-";
			continue;
		}
		else if (s[i] == '+') {
			st.push(temp);
			st.push("+");
			temp = "";
			continue;
		}
		temp.push_back(s[i]);
	}
	st.push(temp);
	while (st.size() != 1) {
		string ch = st.top(); st.pop(); st.pop();
		string ch2 = st.top(); st.pop();
		int sum = stoi(ch) + stoi(ch2);
		st.push(to_string(sum));
	}

	cout << st.top() << "\n";
	
}