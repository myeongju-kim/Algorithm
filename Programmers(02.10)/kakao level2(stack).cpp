#include <string>
#include <vector>
#include <stack>
using namespace std;
string find(int n, stack<string> st, string s) {
	string temp;
	st.push(s.substr(0, n));
	int cnt = 0;

	for (int i = n; i < s.size(); i+=n) {
		string a = s.substr(i, n);
		if (a == st.top()) {
			cnt += 1;
		}
		else {
			if (cnt >= 99) temp += ("000" + st.top());
			else if (cnt >= 9) temp += ("00" + st.top());
			else if (cnt >= 1) temp += ("0" + st.top());
			else temp += st.top();
			cnt = 0;
		}
		st.push(a);
	}
	if (cnt >= 99) temp += ("000" + st.top());
	else if (cnt >= 9) temp += ("00" + st.top());
	else if (cnt >= 1) temp += ("0" + st.top());
	else temp += st.top();
	return temp;
}
int solution(string s) {
    int answer = 999999999;
    for (int i = 1; i <= s.size(); i++) {
        stack<string> st;
		string temp = find(i,st,s);
		if (temp.size() < answer)
			answer = temp.size();
	}
    return answer;
}