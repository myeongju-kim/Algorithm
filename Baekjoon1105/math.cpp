#include <iostream>
#include <string>
#define INF 99999
using namespace std; 


void find(string s, string e, int g) {
	if (s.size() == 0) {
		cout << g << "\n";
		return;
	}
	if (s.size() < e.size()) {
		cout << g << "\n";
		return;
	}
	else {
		if (s == e) {
			int count = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '8')count++;
			}
			cout << count << "\n";
			return;
		}
		if (s[0] == e[0]) {
			if (s[0] == '8') {
				s.erase(0, 1);
				e.erase(0, 1);
				find(s, e, g + 1);
			}
			else {
				s.erase(0, 1);
				e.erase(0, 1);
				find(s, e, g);
			}
		}
		else {
			cout << g << "\n";
			return;
		}
	}
}


int main() { 
	string start, end;
	cin >> start>>end;
	find(start, end,0);
	return 0; 
}

