#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int check(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') st.push(s[i]);
        else {
            if (st.empty()) return 0;
            if (st.top() == '(' && s[i] == ')') st.pop();
            else if (st.top() == '{' && s[i] == '}') st.pop();
            else if (st.top() == '[' && s[i] == ']') st.pop();
        }
    }
    if (st.empty()) return 1;
    else return 0;

}

int main() {
	string s = "}]()[{";
	int cnt = check(s);
    cout << cnt << "\n";
	for (int i = 1; i < s.size(); i++) {
		char temp = s[0];
		s.erase(s.begin());
		s.push_back(temp);
		cnt += check(s);
        cout << cnt << "\n";
       
	}
	return 0;
}