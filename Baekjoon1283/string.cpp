#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
using namespace std; 

vector<char> c = { ' ' };

int check(string s) {
	//첫번째 먼저 검사, 그 다음 빈칸 검사
	int index = 0;
	while (1) {
		char temp;
		if (s[index] >= 65 && s[index] <= 90)
			temp = s[index] + 32;
		else temp = s[index];
		auto it = find(c.begin(), c.end(), temp);
		if (it == c.end()) {
			c.push_back(temp);
			return index;
		}
		int pos = s.find(' ',index);
		if (pos==string::npos)break;
		index = pos+1;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == ' ')continue;
		char temp;
		if (s[i] >= 65 && s[i] <= 90)
			temp = s[i] + 32;
		else temp = s[i];
		auto it = find(c.begin(), c.end(), temp);
		if (it == c.end()) {
			c.push_back(temp);
			return i;
		}
	}

	return -1;
}

int main(void) { 
	ios_base::sync_with_stdio(0); cin.tie(0); 
	vector<string> s;
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		s.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		int w = check(s[i]);
		if (w!=-1) {
			s[i].insert(w, 1,'[');
			s[i].insert(w + 2,1, ']');
		}
	}
	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
	
	return 0; 
}
